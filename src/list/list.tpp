namespace s21 {

template <class T>
list<T>::list() : size_(0), head_(nullptr), tail_(nullptr) {}

template <class T>
list<T>::list(size_type n) : list(){
	for(size_type i = 0; i < n; ++i)
		push_back(value_type());
}

template <class T>
list<T>::list(std::initializer_list<value_type> const &items) : list(){
	for( )
}

template <class T>
list<T>::list(const list &l){

}

template <class T>
list<T>::list(list &&l){

}

template <class T>
list<T>::~list(){

}

}  // namespace s21