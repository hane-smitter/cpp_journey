# 0 "/home/zaki/Documents/programming/cpp_journey/modularity/Vector.cpp"
# 1 "/home/zaki/Documents/programming/cpp_journey/modularity/cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/zaki/Documents/programming/cpp_journey/modularity/Vector.cpp"


# 1 "/home/zaki/Documents/programming/cpp_journey/modularity/Vector.h" 1


class Vector {
public:
    explicit Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;
    int sz;
};
# 4 "/home/zaki/Documents/programming/cpp_journey/modularity/Vector.cpp" 2

Vector::Vector(int s) :elem{new double[s]}, sz{s} {}

double& Vector::operator[](int i) {
    return elem[i];
}

int Vector::size() {
    return sz;
}
