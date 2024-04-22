#include <iostream>
#include <fstream>

struct adress
{
    std::string city;
    std::string street;
    int house_num;
    int home_num;
};

static void fout(adress& a, std::ofstream& out)
{
    out << "city: " << a.city;
    out << ", " << a.street;
    out << ", " << a.house_num;
    out << ", " << a.home_num << std::endl;
}

static void fin(adress& a, std::ifstream &in) 
{
    in >> a.city;
    in >> a.street;
    in >> a.house_num;
    in >> a.home_num;
}
int main()
{
    int a;
    std::ifstream in;
    in.open("in.txt");
    in >> a;
    adress* adress_array = new adress[a];
    for (int i = 0; i < a; ++i)
    {
        fin(adress_array[i], in);
    }
    in.close();
    std::ofstream out;
    out.open("out.txt");
    for (int i = 0; i < a; ++i)
    {
        fout(adress_array[i],out);
    }
    out.close();
    delete[] adress_array;
	return 0;
}