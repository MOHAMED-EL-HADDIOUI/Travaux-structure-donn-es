#include <stdio.h>
#include <iostream>
#include <conio.h>
#include<math.h>
using namespace std;

char decode_letter(string  morse)
{
	char tableau[31]={'H','S','V','I','F','U','0','E','L','R','0','A','P','W','J','0',
	                 'B','D','X','N','C','K','Y','T','Z','G','Q','M','0','O','0'};
	int i=15;
	for(int j=0;j<morse.length();j++)
	{
		if(morse[j]=='.')
		   i-=pow(2,3-j);
		if(morse[j]=='-')
	       i+=pow(2,3-j);
	} 
	return   tableau[i];
}
main()
{
	cout<<"\n.- :"<<decode_letter(".-");
	cout<<"\n-... :"<<decode_letter("-...");
	cout<<"\n-.-. :"<<decode_letter("-.-.");
	cout<<"\n-.. :"<<decode_letter("-..");
	cout<<"\n. :"<<decode_letter(".");
	cout<<"\n..-. :"<<decode_letter("..-.");
	cout<<"\n--. :"<<decode_letter("--.");
	cout<<"\n.... :"<<decode_letter("....");
    cout<<"\n.. :"<<decode_letter("..");
    cout<<"\n.--- :"<<decode_letter(".---");
    cout<<"\n-.- :"<<decode_letter("-.-");
    cout<<"\n.-.. :"<<decode_letter(".-..");
    cout<<"\n-- :"<<decode_letter("--");
    cout<<"\n-. :"<<decode_letter("-.");
    cout<<"\n-. :"<<decode_letter("-.");
    cout<<"\n--- :"<<decode_letter("---");
    cout<<"\n.--. :"<<decode_letter(".--.");
    cout<<"\n--.- :"<<decode_letter("--.-");
    cout<<"\n.-. :"<<decode_letter(".-.");
    cout<<"\n... :"<<decode_letter("...");
    cout<<"\n- :"<<decode_letter("-");
    cout<<"\n..- :"<<decode_letter("..-");
    cout<<"\n...- :"<<decode_letter("...-");
    cout<<"\n.-- :"<<decode_letter(".--");
    cout<<"\n-..- :"<<decode_letter("-..-'");
    cout<<"\n-.-- :"<<decode_letter("-.--");
    cout<<"\n--.. :"<<decode_letter("--..");
}
