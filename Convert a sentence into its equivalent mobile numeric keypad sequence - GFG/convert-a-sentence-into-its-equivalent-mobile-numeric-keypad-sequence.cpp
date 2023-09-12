//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends


string printSequence(string S)
{
    //code here.
    string ans = "";
    for(auto it: S){
        if(it == ' '){
            ans+='0';
        }else if(it == 'A'){
            ans+='2';
        }else if(it == 'B'){
            ans+="22";
        }else if(it == 'C'){
            ans+="222";
        }else if(it == 'D'){
            ans+='3';
        }else if(it == 'E'){
            ans+="33";
        }else if(it == 'F'){
            ans+="333";
        }else if(it == 'G'){
            ans+='4';
        }else if(it == 'H'){
            ans+="44";
        }else if(it == 'I'){
            ans+="444";
        }else if(it == 'J'){
            ans+='5';
        }else if(it == 'K'){
            ans+="55";
        }else if(it == 'L'){
            ans+="555";
        }else if(it == 'M'){
            ans+='6';
        }else if(it == 'N'){
            ans+="66";
        }else if(it == 'O'){
            ans+="666";
        }else if(it == 'P'){
            ans+='7';
        }else if(it == 'Q'){
            ans+="77";
        }else if(it == 'R'){
            ans+="777";
        }else if(it == 'S'){
            ans+="7777";
        }else if(it == 'T'){
            ans+='8';
        }else if(it == 'U'){
            ans+="88";
        }else if(it == 'V'){
            ans+="888";
        }else if(it == 'W'){
            ans+='9';
        }else if(it == 'X'){
            ans+="99";
        }else if(it == 'Y'){
            ans+="999";
        }else{
            ans+="9999";
        }
    }
    return ans;
}