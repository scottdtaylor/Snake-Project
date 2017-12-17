
#ifndef TRIPLET_H
#define TRIPLET_H


template <typename T, typename S, typename R>
class triplet {
public:
	T first;
	S second;
	R third;
	triplet() : first(T()), second(S()), third(R()) {

	}
	triplet(T one, S two, const R three) : first(one), second(two), third(three) {

	}
	triplet(const R& three) : third(three) {

	}
	triplet(const triplet& trip) {
		first = trip.first;
		second = trip.second;
		third = trip.third;
	}
	triplet& operator=(triplet trip) {
		std::swap(first, trip.first);
		std::swap(second, trip.second);
		return *this;
	}
	bool operator<(const triplet& t) {
	switch()
		
	}
};



#endif // !TRIPLET_H
