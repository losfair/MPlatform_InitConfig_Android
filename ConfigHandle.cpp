#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <list>
#include <algorithm>
using namespace std;
class section {
	public:
		string name;
		map<string,string> cfg;
};
list<section> sections;
int main()
{
	char temp[2];
	string left;
	string right;
	section * sec=new section;
	temp[1]='\0';
	temp[0]=0;
	
	sec->name="default";
	
	while(left!="END")
	{
		left="";
		right="";
		temp[0]=0;
		
		temp[0]=getchar();
		while(temp[0]=='\n') temp[0]=getchar();
		
		if(temp[0]=='~')
		{
			while(getchar()!='\n');
			continue;
		}
		if(temp[0]=='[')
		{
			sections.push_back(*sec); //Save the previous *sec
			sec=new section;
			while(temp[0]!=']') {
				temp[0]=getchar();
				if(temp[0]!=']') sec->name.append(temp);
			}
			while(getchar()!='\n');
			continue;
		}
		
		if(temp[0]!='=') left.append(temp);
		while(temp[0]!='=')
		{
			temp[0]=getchar();
			if(temp[0]!='=') left.append(temp);
		}
		while(temp[0]!='\n')
		{
			temp[0]=getchar();
			if(temp[0]!='\n') right.append(temp);
		}
//		cout<<left<<" "<<right<<endl;
		if(left!="END") sec->cfg.insert(pair<string,string>(left,right));
	}
	sections.push_back(*sec);
	
	cout<<"**************"<<endl;
	for(list<section>::iterator sit=sections.begin();sit!=sections.end();sit++)
	{
		cout<<"In section "<<sit->name<<": "<<endl;
		sec=new section;
		*sec=*sit;
		for(map<string,string>::iterator cit=sec->cfg.begin();cit!=sec->cfg.end();cit++)
		cout<<"- "<<cit->first<<" == "<<cit->second<<endl;
	}
	cout<<"**************"<<endl;
	return 0;
}
