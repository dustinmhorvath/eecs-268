

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size){
	T temp = 0;
	for(int i = 0; i < size-1; i++){
		for(int j = 0; j < size-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size){
	while(!isSorted(arr, size)){
		shuffle(arr, size);
	}
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size){
	T temp;
	int index;
	for(int i = 1 ; i < size; i++){
		temp = arr[i];
		index = i;
		while(index > 0 and arr[index-1] > temp){
			arr[index] = arr[index-1];
			index = index - 1;
		}
		arr[index] = temp;
	}
}

template<typename T>
void Sorts<T>::mergeSort(T arr[], int size){
	if(size > 1){
		if(size % 2 == 0){
			T* leftHalf = arr;
			T* rightHalf = arr + size/2;

			mergeSort(leftHalf, size/2);
			mergeSort(rightHalf, size/2);
			merge(leftHalf, rightHalf, size/2, size/2);
		}
		else{
			T* leftHalf = arr;
			T* rightHalf = arr + size/2;

			mergeSort(leftHalf, size/2);
			mergeSort(rightHalf, size/2 + 1);
			merge(leftHalf, rightHalf, size/2, size/2 + 1);
		}
	}
}

template<typename T>
void Sorts<T>::merge(T* left, T* right, int sizeLeft, int sizeRight){
	T* merged = new T[sizeLeft + sizeRight];
	int mergedIndex = 0;
	int leftIndex = 0;
	int rightIndex = 0;
	while(leftIndex < sizeLeft && rightIndex < sizeRight){
		if(left[leftIndex] <= right[rightIndex]){
			merged[mergedIndex] = left[leftIndex];
			mergedIndex++;
			leftIndex++;
		}
		else{
			merged[mergedIndex] = right[rightIndex];
			mergedIndex++;
			rightIndex++;
		}
	}

	while(leftIndex < sizeLeft){
		merged[mergedIndex] = left[leftIndex];
		mergedIndex++;
		leftIndex++;
	}
	while(rightIndex < sizeRight){
		merged[mergedIndex] = right[rightIndex];
		mergedIndex++;
		rightIndex++;
	}

	for(int i = 0; i < (sizeLeft + sizeRight); i++){
		left[i] = merged[i];
	}
	delete[] merged;
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size){
	int min = 0;
	T temp;
	for(int i = 0; i < size - 1; i++){
		min = i;
		for(int j = i + 1; j < size; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		//Might be worth doing an if(min != i) here for this block.
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size){
	bool sorted = true;
	for(int i = 0; i < size - 1; i++){
		if(arr[i] > arr[i + 1]){
			sorted = false;
		}
	}
	return sorted;
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size){
	static std::default_random_engine generator(time(nullptr));
	static std::uniform_int_distribution<int> distribution(0,size - 1);
	double value = 0.0;
	int loc = 0;
	for(int i = 0; i < size; i++){
		loc = distribution(generator);
		value = arr[i];
		arr[i] = arr[loc];
		arr[loc] = value;
        }
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size){
	quickSortRec(arr, 0, size - 1, false);
}

template <typename T>
void Sorts<T>::quickSortMedian(T arr[], int size){
	quickSortRec(arr, 0, size - 1, true);
}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median){
	if(median){
		setMedianPivot(arr, first, last);
	}
	int pivot = last;
	T temp;
	int left = first;
	int right = last - 1;
	while(left < right){
		if(arr[left] > arr[right]){
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		while(arr[left] <= arr[pivot] && left < pivot){
			left++;
		}
		while(arr[right] >= arr[pivot] && right > 0){
			right--;
		}
	}

	if(arr[left] > arr[pivot]){
		temp = arr[left];
		arr[left] = arr[pivot];
		arr[pivot] = temp;
		return left;
	}
	else return pivot;
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last){
	int median = (first + last) / 2;
	T temp = arr[median];
	arr[median] = arr[last];
	arr[last] = temp;
}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median){
	if(first < last){
		int pivot = partition(arr, first, last, median);
		if(pivot > 0){
			quickSortRec(arr, first, pivot - 1, median);
		}
		if(pivot < last){
			quickSortRec(arr, pivot + 1, last, median);
		}
	}

}
