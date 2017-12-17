
#ifndef TRIPLET_H
#define TRIPLET_H

//trying something
template <typename T, typename S, typename R, typename Q>
class quad {
public:
	T first;
	S second;
	R third;
	Q fourth;
	quad() : first(T()), second(S()), third(R()), fourth(STOPPED) {

	}
	quad(T one, S two, R three, Q four) : first(one), second(two), third(three), fourth(four) {

	}
	quad(const R& three) : third(three) {

	}

	quad(const quad& quad) {
		first = quad.first;
		second = quad.second;
		third = quad.third;
		fourth = quad.fourth;
	}
	quad& operator=(quad quad) {
		std::swap(first, quad.first);
		std::swap(second, quad.second);
		std::swap(third, quad.third);
		std::swap(fourth, quad.fourth);
		return *this;
	}

};



#endif // !TRIPLET_H
