/**
*	@file Queue.hpp
*	@author John Gibbons
*	@date 2014.04.02
*/

template <typename T>
Queue<T>::Queue() : m_size(0), m_front(nullptr), m_back(nullptr)
{ }


template <typename T>
Queue<T>::~Queue()
{
	while(!isEmpty())
	{
		dequeue();
	}
}

template <typename T>
bool Queue<T>::isEmpty() const 
{
	return (m_size==0);
}


template <typename T>
void Queue<T>::enqueue(const T newEntry)
{
	if(m_front == nullptr)
	{
		m_front = new Node<T>(newEntry);
		m_back = m_front;
	}
	else
	{
		Node<T>* temp = new Node<T>(newEntry);
		m_back->setPrevious(temp);			
		m_back = temp;
	}
	
	m_size++;
}

template <typename T>
T Queue<T>::dequeue() throw(PreconditionViolationException)
{
	if(m_size>1)
	{
		Node<T>* temp = m_front->getPrevious();
		T tempValue = m_front->getValue();
		delete m_front;
		m_front = temp;
		m_size--;	
		return(tempValue);
	}
	else if (m_size == 1)
	{
		T tempValue = m_front->getValue();
		delete m_front;
		m_front = nullptr;
		m_back = nullptr;
		m_size--;
		return(tempValue);		
	}
	else
	{
		throw(PreconditionViolationException("Dequeue attempted on an empty queue"));
	}
}

template <typename T>
T Queue<T>::peekFront() const throw(PreconditionViolationException)
{
	if(m_size > 0)
	{
		return(m_front->getValue());
	}
	else
	{
		throw( PreconditionViolationException("Peak attempted on empty queue") );
	}
}

template <typename T>
int Queue<T>::size() const
{
	return(m_size);
}


template <typename T>
void Queue<T>::print() const
{	
	if(isEmpty())
	{
		std::cout << "Queue Empty" << std::endl;
	}
	else	
	{
		Node<T>* tempPtr = m_front;
		while(tempPtr != nullptr)
		{
			std::cout << tempPtr->getValue();
			tempPtr = tempPtr->getPrevious();
			if(tempPtr != nullptr) 
			{
				std::cout << ","; 
			}
		}
		std::cout << std::endl;
	}
}

