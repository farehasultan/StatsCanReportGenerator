#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

template <class T>
class CompareBehaviour{
	public:
		virtual bool compare(T,T)=0;
};

#endif

