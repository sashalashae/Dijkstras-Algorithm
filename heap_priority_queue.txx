

#include "dynamic_array_list.h"
#include "heap_priority_queue.h"
#include <iostream>
#include <ostream>
using namespace std;


/*
Checks the size of the list and returns true and false
*/
template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
	return confused.isEmpty();
}


template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
	confused.insert(confused.getLength(), item); //inserts the item into the list
	long i = confused.getLength(); //child
	long j = (i >> 1) - 1; //parent
	i--;

	while (j >= 0 && confused.getEntry(j) > confused.getEntry(i))
	{
		//if (confused.getEntry(j) < confused.getEntry(i-1))
		//{
		T curr = confused.getEntry(i);
		confused.setEntry(i, confused.getEntry(j));
		confused.setEntry(j, curr);
		i = j;
		j = ((i - 1) >> 1);
		//}
	}
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
	if (confused.isEmpty() == true) //Checks to see if the
	{
		throw std::logic_error("Your item is not in the index.");
	}
	else if (confused.getLength() == 1 && confused.isEmpty() == false)
	{
		confused.remove(0);
	}
	else
	{
		confused.setEntry(0, confused.getEntry(confused.getLength() - 1)); //Shifts the last item to the front position
		confused.remove(confused.getLength() - 1); //deletes the new front item from the last position to eleminate duplication
		long p = 0; //Sets the parent equal to 0
		long lc = (2 * p) + 1; //sets the lower child
		while (lc < confused.getLength()) //runs as long as the lower child is less than the length of the array
		{
			long rc = lc + 1; //sets the right child position
			long fam = lc; //creates a temporary holder caled
			if (rc < confused.getLength()) //right child
			{
				if (confused.getEntry(rc) < confused.getEntry(lc)) //checks to see if right child is greater then the left child
				{
					fam = rc; //sets the top value equal to the right child
				}
			}
			if (confused.getEntry(fam) < confused.getEntry(p)) //checks to see if the parent value is less then the top change value
			{
				T curr = confused.getEntry(fam); //Serves a placeholder for the current item
				confused.setEntry(fam, confused.getEntry(p)); //set the parent item equal to the 
				confused.setEntry(p, curr); //sets the temporary holder to the parent position
				p = fam;
				lc = (2 * p) + 1;
			}
			else
			{
				break;
			}
		}
	}
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
	bool check = false;
	if (confused.isEmpty() == false)
	{
		return confused.getEntry(0);
	}
	else
	{
		throw std::logic_error("Your item is not in the index.");
	}
}

