# include <iostream>
# include <vector>

using namespace std;

int main(){

    vector <int> vector1{}, vector2{};

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "vector1[0] = " << vector1.at(0) << endl;
    cout << "vector1[1] = " << vector1.at(1) << endl;
    cout << "Size of vector1: " << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "vector2[0] = " << vector2.at(0) << endl;
    cout << "vector2[1] = " << vector2.at(1) << endl;
    cout << "Size of vector2: " << vector2.size() << endl;

    vector <vector<int>> vector_2d {};

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "vector_2d[0][0] = " << vector_2d.at(0).at(0) << endl;
    cout << "vector_2d[0][1] = " << vector_2d.at(0).at(1) << endl;
    cout << "vector_2d[1][0] = " << vector_2d.at(1).at(0) << endl;
    cout << "vector_2d[1][1] = " << vector_2d.at(1).at(1) << endl;
    
    vector1.at(0) = 1000;
    cout << "\nChanging vector1[0] to 1000" << endl << endl;

    cout << "vector_2d[0][0] = " << vector_2d.at(0).at(0) << endl;
    cout << "vector_2d[0][1] = " << vector_2d.at(0).at(1) << endl;
    cout << "vector_2d[1][0] = " << vector_2d.at(1).at(0) << endl;
    cout << "vector_2d[1][1] = " << vector_2d.at(1).at(1) << endl;

    cout << "vector1[0] = " << vector1.at(0) << endl;
    cout << "vector1[1] = " << vector1.at(1) << endl;
    cout << "Size of vector1: " << vector1.size() << endl;

    return 0;
}