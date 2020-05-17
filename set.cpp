#include <iostream>
using namespace std;

template<class F>
class Comparator{
public:
    int paritate(F x, F y)
    {
        if(x&2==y%2)
            return true;
        return false;
    }
};

template <typename T, class F = Comparator<T> >
class Set {
private:
	T *p;
	int size;
public:
	Set();
	Set(T arr[], int s);
	~Set();
	Set(const Set &s);
	void operator=(const Set &s);
	void add(int s);
	void deleteEl(int s);
	void print();
	bool exist(int s);
	void nr(T arr[]);
};

template <typename T, class F>
Set<T,F>::Set() {
	p = new T[0];
	size = 0;
	for(int i = 0; i < size; i++)
		p[i] = NULL;
}

template <typename T, class F>
Set<T,F>::Set(T arr[], int s) {
	p = new T[s];
	size = s;
	for(int i = 0; i < size; i++)
		p[i] = arr[i];
}

template <typename T, class F>
Set<T,F>::~Set() {
    delete p;
}

template <typename T, class F>
void Set<T,F>::operator=(const Set &s) {
    delete p;
    size=s.nr();
    s=new T[size];
    for(int i=0; i<size; i++)
        p[i]=s.p[i];
}

template <typename T, class F>
Set<T,F>::Set(const Set &s){
    p = new T[size];
    for(int i=0; i<size; i++)
        p[i]=p[i];
}


template <typename T, class F>
void Set<T,F>::add(int s) { //T arr[]
    p[size] = s;
    size++;
}

template <typename T, class F>
void Set<T,F>::deleteEl(int s) {
    int aux[size];
    int j=0;
    for(int i=0; i<size; i++)
        if(p[i] != s)
        {
            aux[j] = p[i];
            j++;
        }
    for(int i=0; i<size; i++)
        p[i] = -1;
    for(int i=0; i<j; i++)
        p[i] = aux[i];
}


template <typename T, class F>
void Set<T,F>::print() {
	for (int i = 0; i < size; i++)
		if(p[i]!= -1)
		    cout<<" "<<*(p + i);
	cout<<endl;
}

template <typename T, class F>
bool Set<T,F>::exist(int s) {
    int ok=0;
    for(int i = 0; i < size; i++)
        if(p[i]==s)
            cout<<s<<" exista in set."<<endl;
            ok=1;
    if(ok==0)
            cout<<"Nu exista in set."<<endl;
}

template<typename T, class F>
void Set<T,F>::nr(T arr[]){
    int n=0;
    for(int i=0; i<size; i++)
        if(p[i]!=-1)
        n++;
    cout<<"Setul are "<<n<<" elemente."<<endl;
}

template<typename T, class F>
ostream &operator<<(ostream &out, Set<T,F>& s){
    for(int i=0; i<s.nr();i++)
        out<<s[i]<<" ";
    out<<endl;
    return out;
}

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	Set<int> a(arr, 5);
	a.print();
	a.add(6);
	a.print();
	a.deleteEl(3);
	a.print();
	a.exist(4);
	a.nr(arr);
	return 0;
}
