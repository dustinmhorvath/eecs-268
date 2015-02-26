

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size){
	int temp = 0;
	for(int i = 0; i < size-1; i++){
		for(int j = 0; j < size-1; j++){
			if(arr[i] > arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}

template<typename T>
T* Sorts<T>::mergeSort(T arr[], int size){
	if(size <= 1){
		return(arr);
	}
	else{
		if(size % 2 == 0){
			T* leftHalf = arr;
			T* rightHalf = arr + size/2;

			return merge(mergeSort(leftHalf, size/2), mergeSort(rightHalf, size/2), size/2, size/2);
		}
		else{
			T* leftHalf = arr;
			T* rightHalf = arr + size/2;

			return merge(mergeSort(leftHalf, size/2), mergeSort(rightHalf, size/2 + 1), size/2, size/2 + 1);
		}
	}

}

template<typename T>
T* Sorts<T>::merge(T* left, T* right, int sizeLeft, int sizeRight){
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
//	left = merged;
//	delete merged;
//	return left;
	return merged;
}
