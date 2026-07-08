#include "Sorter.h"


//
// Part A-2
//
/*
procedure bubbleSort(A : list of sortable items)
	n := length(A)
	repeat
		swapped := false
		for i := 1 to n - 1 inclusive do
			if A[i - 1] > A[i] then
				swap(A, i - 1, i)
				swapped = true
			end if
		end for
		n := n - 1
	while swapped
end procedure
*/
void Sorter::bubbleSort(std::vector<Light>& A) const
{
	//n := length(A)
	int n = A.size();
	bool swapped = false;
	//repeat
	do
	{
		swapped = false;//swapped := false
		//for i := 1 to n - 1 inclusive do
		for (int i = 1; i <= n-1; i++)
		{
			//if A[i - 1] > A[i] then
			if (A[i - 1].red > A[i].red)
			{
				//swap(A, i - 1, i) ??
				//OG Swap:
				////1) temp = A[i-1]
				//Light temp = A[i - 1];
				////2) A[i-1] = A[i]
				//A[i - 1] = A[i];
				////3) A[i] = temp
				//A[i] = temp;

				//NG Swap:
				std::swap(A[i - 1], A[i]);
				
				//swapped = true
				swapped = true;
			}//end if
		}//end for
		//n := n - 1
		--n;
	} while (swapped);//while swapped
}//end procedure
