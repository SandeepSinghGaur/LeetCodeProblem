/*
No more nested min(x, min(y, ...))

Use initializer list and std::min and std::max to make life easy

small = min(x, min(y, min(z, k))); // the old way
small = min({x, y, z, k}); // life is easy

//Same for the finding max element
*/

/*
JavaScript like Destructuring using Structured Binding in C++

pair<int, int> cur = {1, 2};
auto [x, y] = cur;
// x is now 1, y is now 2
// no need of cur.first and cur.second

array<int, 3> arr = {1, 0, -1};
auto [a, b, c] = arr;
// a is now 1, b is now 0, c is now -1

*/

/*
Generic Reader and Writer for multiple variables and containers

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(string delimiter, T &&...args) {
    ((cout << args << delimiter), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(string delimiter, T &t) {
    for (const auto &e : t) {
        write(delimiter, e);
    }
    write("\n");
}

Usage

// Question: read three space seprated integers and print them in different lines.
	int x, y, z;
	read(x, y, z);
	write("\n", x, y, z);
	
// even works with variable data types :)
	int n;
	string s;
	read(n, s);
	write(" ", s, "has length", n, "\n");
	
// Question: read an array of `N` integers and print it to the output console.
	int N;
	read(N);
	vector<int> arr(N);
	readContainer(arr);
	writeContainer(" ", arr); // output: arr[0] arr[1] arr[2] ... arr[N - 1]
	writeContainer("\n", arr);
	
	* output:
	* arr[0]
	* arr[1]
	* arr[2]
	* ...
	* ...
	* ...
	* arr[N - 1]
	

*/