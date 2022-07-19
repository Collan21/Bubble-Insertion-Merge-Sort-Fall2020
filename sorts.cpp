#include <iostream>
#include <vector>

using namespace std;

/**
*  Function 1: Bubble Sort
*  Paremeters: the address of a vector of strings
*  
*  for i from 0 to vector size - 1
*
*      for j from (i + 1) to vector size - 1
*
*          if the string in the current vector is alphabetically behind the 
*          string in the next index
*          
*              swap the strings
**/
void BubbleSort(std::vector<std::string> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    for (int j = i + 1; j < vec.size(); j++) {
      if (vec[i].compare(vec[j]) > 0) {
        string temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }
}

/**
*  Function 2: Insert
*  Paremeters: Address of a vector of integers, an integer that stores
*              the value needs to be inserted, and an integer for the 
*              size of the vector
*
*  if the vector size is less than 0 or if the last element in the vector is
*  less than the value that needs to be inserted, this indicates a base case
*
*      set the value in the next index on the vector to the insert value
*
*      break
*
*  else
*
*      set the value in the next index of the vector to the current index value
*
*      call Insert with the same parameters but without the last index of the
*      vector
**/
void Insert(std::vector<int>& v, int curr_elem, int vector_size) {
  if (vector_size < 0 || v[vector_size] < curr_elem) {
    v[vector_size + 1] = curr_elem;
    return;
  }

  v[vector_size + 1] = v[vector_size];
  Insert(v, curr_elem, vector_size - 1);
}

/**
*  Function 3: Insertion Sort Helper
*  Paremeters: Address of a vector of integers, an integer for the 
*              size of the vector
*  
*  if the vector is empty
*  
*      return
*
*  else
*
*      call insertion sort helper without the last index of the vector
*
*      insert sorted index into it's necessary location
**/
void InsertionSortHelper(std::vector<int>& v, int vector_size) {
  if (vector_size == 0)
    return;

  InsertionSortHelper(v, vector_size - 1);
  Insert(v, v[vector_size], vector_size - 1);
}

/**
*  Function 4: Insertion Sort
*  Paremeters: the address of a vector of integers
*  
*  calls InsertionSortHelper with the vector passed in, and the high index of
*  the original vector to kick start InsertionSortHelper
**/
void InsertionSort(std::vector<int>& v) {
  InsertionSortHelper(v, v.size() - 1);
}

/**
*  Function 5: Merge
*  Paremeters: The address of a vector, 3 integers to store the low, middle,
*              and high indexes of a vector
*  
*  copy the first half of the original vector into the "left" vector
*  
*  copy the second half of the vector into the "right" vector
*
*  while the left and right vector's indexes are in bounds of the vector
*    
*      if the value in the left vector index (l.v.i.) is alphabetically ahead
*      of or equal to the value in the r.v.i.
*      
*          then the original vector should now store the value in the l.v.i.
*      
*          go to the next l.v.i. 
*    
*      if the value in the r.v.i. is alphabetically ahead of or equal to the 
*      value in the l.v.i.
*      
*          then the original vector should now store the value in the r.v.i.
*      
*          go to the next r.v.i.
*    
*      go to the next original vector index
*
*  copy the rest of the left vector into the final vector
*
*  copy the rest of the right vector into the final vector
**/
void Merge(std::vector<std::string> &vec, int left, int mid, int right) {
  int lvec_size = mid - left + 1, //if mid and left are 0, then the size is 1
                                  //this same logic applies to all values
      rvec_size = right - mid;    //the last index is right - 1 (r - 1 - m + 1)

  vector<string> left_vec(lvec_size),
                 right_vec(rvec_size);
  
  for (int i = 0; i < lvec_size; i++) 
    left_vec[i] = vec[left + i];
  
  for (int i = 0; i < rvec_size; i++) 
    right_vec[i] = vec[mid + 1 + i]; //mid + 0 would be the upper bound of the
                                     //the first half vector
  
  int index_in_lvec = 0,
      index_in_rvec = 0,
      index_in_original = left;

  while (index_in_lvec < lvec_size && index_in_rvec < rvec_size) {
    if (left_vec[index_in_lvec].compare(right_vec[index_in_rvec]) <= 0) {
      vec[index_in_original] = left_vec[index_in_lvec];
      index_in_lvec++;
    }

    else {
      vec[index_in_original] = right_vec[index_in_rvec];
      index_in_rvec++;
    }

    index_in_original++;
  }

  while (index_in_lvec < lvec_size) {
    vec[index_in_original] = left_vec[index_in_lvec];
    index_in_lvec++;
    index_in_original++;
  }

  while (index_in_rvec < rvec_size) {
    vec[index_in_original] = right_vec[index_in_rvec];
    index_in_rvec++;
    index_in_original++;
  }
}

/**
*  Function 6: Merge Sort Helper
*  Paremeters: The address of a vector, and 2 integers to store the low,
*              and high indexes of a vector
*  
*  if the low index is less than the high index
*
*      set the mid index 
*
*      call merge sort helper with the same low index, and the mid index
*      as the new high index
*
*      call merge sort helper with the the mid index + 1 as the low index,
*      and the same high index
*
*      merge the two halves
**/
void MergeSortHelper(std::vector<std::string> &vec, int left, int right) {
  if (left < right) {
    int mid = (left + right - 1) / 2;
    MergeSortHelper(vec, left, mid);
    MergeSortHelper(vec, mid + 1, right);

    Merge(vec, left, mid, right);
  }
}

/**
*  Function 4: Merge Sort
*  Paremeters: the address of a vector of strings
*  
*  calls MergeSortHelper with the vector passed in, and the original vector's
*  first and last indexes
**/
void MergeSort(std::vector<std::string> &vec) {
  MergeSortHelper(vec, 0, vec.size() - 1);
}