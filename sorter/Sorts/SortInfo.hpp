template <typename T>
SortInfo<T>::SortInfo(std::function<void(T[], T)> sort, std::string name){
	m_sort = sort;
	m_name = name;
	m_time = 0.0;
	m_count = 0;

}

template <typename T>
std::function<void(T[], int)> SortInfo<T>::getSort() const{
	return m_sort;
}

template <typename T>
std::string SortInfo<T>::getName() const{
	return m_name;
}

template <typename T>
double SortInfo<T>::getTime() const{
	return m_time;
}

template <typename T>
void SortInfo<T>::setTime(double t){
	m_time = t;	
}

template <typename T>
int SortInfo<T>::getCount() const{
	return m_count;
}

template <typename T>
void SortInfo<T>::setCount(int c){
	m_count = c;
}
