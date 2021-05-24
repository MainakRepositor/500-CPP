#include <iostream>
using namespace std;

// Heap capacity
#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

//// Utility functions

// exchange a and b
inline
void Exch(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

// Greater and Smaller are used as comparators
bool Greater(int a, int b)
{
	return a > b;
}

bool Smaller(int a, int b)
{
	return a < b;
}

int Average(int a, int b)
{
	return (a + b) / 2;
}

// Signum function
// = 0 if a == b - heaps are balanced
// = -1 if a < b - left contains less elements than right
// = 1 if a > b - left contains more elements than right
int Signum(int a, int b)
{
	if( a == b )
		return 0;

	return a < b ? -1 : 1;
}

// Heap implementation
// The functionality is embedded into
// Heap abstract class to avoid code duplication
class Heap
{
public:
	// Initializes heap array and comparator required
	// in heapification
	Heap(int *b, bool (*c)(int, int)) : A(b), comp(c)
	{
		heapSize = -1;
	}

	// Frees up dynamic memory
	virtual ~Heap()
	{
		if( A )
		{
			delete[] A;
		}
	}

	// We need only these four interfaces of Heap ADT
	virtual bool Insert(int e) = 0;
	virtual int GetTop() = 0;
	virtual int ExtractTop() = 0;
	virtual int GetCount() = 0;

protected:

	// We are also using location 0 of array
	int left(int i)
	{
		return 2 * i + 1;
	}

	int right(int i)
	{
		return 2 * (i + 1);
	}

	int parent(int i)
	{
		if( i <= 0 )
		{
			return -1;
		}

		return (i - 1)/2;
	}

	// Heap array
	int *A;
	// Comparator
	bool (*comp)(int, int);
	// Heap size
	int heapSize;

	// Returns top element of heap data structure
	int top(void)
	{
		int max = -1;

		if( heapSize >= 0 )
		{
			max = A[0];
		}

		return max;
	}

	// Returns number of elements in heap
	int count()
	{
		return heapSize + 1;
	}

	// Heapification
	// Note that, for the current median tracing problem
	// we need to heapify only towards root, always
	void heapify(int i)
	{
		int p = parent(i);

		// comp - differentiate MaxHeap and MinHeap
		// percolates up
		if( p >= 0 && comp(A[i], A[p]) )
		{
			Exch(A[i], A[p]);
			heapify(p);
		}
	}

	// Deletes root of heap
	int deleteTop()
	{
		int del = -1;

		if( heapSize > -1)
		{
			del = A[0];

			Exch(A[0], A[heapSize]);
			heapSize--;
			heapify(parent(heapSize+1));
		}

		return del;
	}

	// Helper to insert key into Heap
	bool insertHelper(int key)
	{
		bool ret = false;

		if( heapSize < MAX_HEAP_SIZE )
		{
			ret = true;
			heapSize++;
			A[heapSize] = key;
			heapify(heapSize);
		}

		return ret;
	}
};

// Specilization of Heap to define MaxHeap
class MaxHeap : public Heap
{
private:

public:
	MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &Greater) { }

	~MaxHeap() { }

	// Wrapper to return root of Max Heap
	int GetTop()
	{
		return top();
	}

	// Wrapper to delete and return root of Max Heap
	int ExtractTop()
	{
		return deleteTop();
	}

	// Wrapper to return # elements of Max Heap
	int GetCount()
	{
		return count();
	}

	// Wrapper to insert into Max Heap
	bool Insert(int key)
	{
		return insertHelper(key);
	}
};

// Specilization of Heap to define MinHeap
class MinHeap : public Heap
{
private:

public:

	MinHeap() : Heap(new int[MAX_HEAP_SIZE], &Smaller) { }

	~MinHeap() { }

	// Wrapper to return root of Min Heap
	int GetTop()
	{
		return top();
	}

	// Wrapper to delete and return root of Min Heap
	int ExtractTop()
	{
		return deleteTop();
	}

	// Wrapper to return # elements of Min Heap
	int GetCount()
	{
		return count();
	}

	// Wrapper to insert into Min Heap
	bool Insert(int key)
	{
		return insertHelper(key);
	}
};

// Function implementing algorithm to find median so far.
int getMedian(int e, int &m, Heap &l, Heap &r)
{
	// Are heaps balanced? If yes, sig will be 0
	int sig = Signum(l.GetCount(), r.GetCount());
	switch(sig)
	{
	case 1: // There are more elements in left (max) heap

		if( e < m ) // current element fits in left (max) heap
		{
			// Remore top element from left heap and
			// insert into right heap
			r.Insert(l.ExtractTop());

			// current element fits in left (max) heap
			l.Insert(e);
		}
		else
		{
			// current element fits in right (min) heap
			r.Insert(e);
		}

		// Both heaps are balanced
		m = Average(l.GetTop(), r.GetTop());

		break;

	case 0: // The left and right heaps contain same number of elements

		if( e < m ) // current element fits in left (max) heap
		{
			l.Insert(e);
			m = l.GetTop();
		}
		else
		{
			// current element fits in right (min) heap
			r.Insert(e);
			m = r.GetTop();
		}

		break;

	case -1: // There are more elements in right (min) heap

		if( e < m ) // current element fits in left (max) heap
		{
			l.Insert(e);
		}
		else
		{
			// Remove top element from right heap and
			// insert into left heap
			l.Insert(r.ExtractTop());

			// current element fits in right (min) heap
			r.Insert(e);
		}

		// Both heaps are balanced
		m = Average(l.GetTop(), r.GetTop());

		break;
	}

	// No need to return, m already updated
	return m;
}

void printMedian(int A[], int size)
{
	int m = 0; // effective median
	Heap *left = new MaxHeap();
	Heap *right = new MinHeap();

	for(int i = 0; i < size; i++)
	{
		m = getMedian(A[i], m, *left, *right);

		cout << m << endl;
	}

	// C++ more flexible, ensure no leaks
	delete left;
	delete right;
}
// Driver code
int main()
{
	int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
	int size = ARRAY_SIZE(A);

	// In lieu of A, we can also use data read from a stream
	printMedian(A, size);

	return 0;
}
