#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

string to_lower(string input) /*problems with this function*/
{
    string result = "";
    char buffer;
    for(int i =0; i< input.length(); ++i)
    {
        if(int(input[i]) > 64 && int(input[i]) <= 91 )
        {
            buffer = input[i] + 32;

        }
        else
        {
            buffer = input[i];
        }
        result += buffer;
    }

    return result;

}

string delete_all_(string input)
{
    string result = "";

    for(int i =0; i< input.length(); ++i)
    {
        char current = input[i];

        if( int(current) == 32 || (int(current)>=64 && int (current) <= 90) || (int(current) >= 96 && int(current) <= 122))
                result += current;
    }

    return result;
}


vector <string> split(char delimeter, string input)
{

    vector<string> result;
    string buffer = "";

    int i = 0;

    while(i < input.length() && buffer[i] == delimeter)
        i++;

    while(i < input.length())
    {

        if(input[i]!= delimeter)
            buffer = buffer + input[i];

        if(input[i] == delimeter)
        {
            if(buffer.length()!=0)
            {


            result.push_back(buffer);

            }
            buffer = "";

        }

        i++;
    }
    if(buffer.length() >0)
        result.push_back(buffer);



    return result;


}


vector <string> Words(vector <string> input)

{
    vector<string> result;
    vector<string> buffer;
    string Without_capital;
    string Without_non_letters;

    for(int i =0; i < input.size(); ++i)
    {
        Without_capital = to_lower(input[i]);
        Without_non_letters = delete_all_(Without_capital);

        buffer = split(' ', Without_non_letters);

        for(int j = 0; j < buffer.size(); ++j )
            result.push_back(buffer[j]);

    }


    return result;


}


map<string, int> my_dictionary( vector <string> dict)
{
    map<string, int> result;

    for(int i = 0; i < dict.size(); ++i )
    {

        if(result.count(dict[i])   > 0)
        {
           result[dict[i]] += 1;

        }
        else
        {
            result[dict[i]] = 1;

        }


    }

    return result;


}


vector <pair<string, int> >map_to_pair(map<string, int> input)
{

    vector < pair<string, int> > result;
    pair <string, int> buffer;

    for(map<string, int> :: iterator it = input.begin(); it!= input.end(); ++it)
    {
        buffer = make_pair(it->first, it->second);
        result.push_back(buffer);


    }
    return result;

}


vector <string> fill1()
{


    vector <string> t;
    t.push_back("jknfcjibfh");
    t.push_back("hvguyhc");
    return t;

}

bool mycomp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;


}

int main()

{
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");
    string S;
    vector<string> dict1;

    int number_of_strings = 0;

    while(getline(in, S))
    {
        number_of_strings++;
        dict1.push_back(S);

    }

    char t = 'A';
    cout<<char(t + 32);

    vector<string> res;
    res = Words(dict1);

    for(int i =0; i < 100; ++i)
        cout << res[i]<< " ";

    map<string, int> result2;

    result2 = my_dictionary(res);
    vector <pair<string, int> > result3;


    result3 = map_to_pair(result2);

    sort(result3.begin(), result3.end(), mycomp);

    for(int i =0; i < result3.size(); ++i )
    {

        out << result3[i].first << " " << result3[i].second << endl;
    }

    /*for(map <string, int> :: iterator it = result2.begin(); it!=result2.end(); ++it)
    {
        out << it->first<< " "<< it->second <<endl;

    }

    */



    return 0;

}
