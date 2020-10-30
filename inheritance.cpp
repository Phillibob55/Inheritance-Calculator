#include <iostream>
using namespace std;

int main(){
	cout << "______________________________________________________\n\n";
	cout << "Inheritance Calculator\nbased on Shariah Law\nBy Muhammad Luqman\nFA20/BSAI/005\nFounder of Shinzou Studios\n";
	cout << "______________________________________________________\n\n\n";
	
//variable declaration
	float asset=0;
	char gender='x';
	bool married = 0;
	
	float father = 0;
	float sfather =0;
	
	float mother = 0;
	float smother=0;
	
	float pgfather = 0;
	float spgfather = 0;
	
	float pgmother = 0;
	float spgmother = 0;
	
	float mgmother = 0;
	float smgmother = 0;
	
	float sister = 0;
	float ssister = 0;
	
	float brother = 0;
	float sbrother = 0;
	
	float son = 0;
	float sson = 0;
	
	float daughter = 0;
	float sdaughter = 0;

	float gson = 0;
	float sgson = 0;
	
	float gdaughter = 0;
	float sgdaughter = 0;
	
	float wife = 0;
	float swife = 0;
	
	float husband = 0;
	float shusband = 0;
	
	float residue = 0;
	
	cout << "If a yes/no question is asked, answer 1 for yes and 0 for no.\nInheritance calculation for siblings of deceased in still under development.\n";
	
// personal information
	cout <<"\nEnter total asset amount left after clearing any debts of the deceased and fulfilling the deceased's will: ";
	cin>> asset;
	if (!asset)
	{
		cout <<"Nothing to share"<<endl;
		return 0;
	}
	
	for (;gender!='f' && gender!='m';)
	{
		cout <<"write gender of deceased as 'm' or 'f':";
		cin>>gender;
	}
	
	cout <<"Is father alive?";
	cin>>father;
	
	if (!father)
	{
		cout <<"Is paternal grand father alive?";
		cin>>pgfather;
		if (!mother)
		{
			cout <<"Is patenal grand mother alive?";
			cin>>pgmother;	
		}
	}
	
	cout <<"Is Mother alive?";
	cin>>mother;
	
	if (!mother)
	{
		cout <<"Is maternal grand mother alive?";
		cin>>mgmother;	
	}

	cout << "How many full sisters are alive?";
	cin>>sister;

	cout << "How many full brothers are alive?";
	cin>>brother;

	cout << "Write marrital status:"<<endl<<"(Write 1 for married and 0 for unmarried)"<<endl;
	cin>>married;


//  Case 1: married
	if (married)
	{
		if (gender=='m')
		{
			cout << "How many wives are alive?" << endl;
			cin >> wife;
		}
		else
		{
			cout << "Is the husband alive?" << endl;
			cin >> husband;
		}
		
		cout << "How many daughters are alive?";
		cin>>daughter;
		
		cout << "How many sons are alive?";
		cin>>son;
		
		if (!son && !daughter)
		{
			cout << "How many Grand daughters are alive?";
			cin>>gdaughter;
			
			cout << "How many Grand sons are alive?";
			cin>>gson;			
		}
	}
		
		
	
	//share calculation
	
	
	if (married)
	{
		//spouse	
		if (husband)
		{
			if (!son && !daughter && !gson && !gdaughter)
			{
				shusband=1.0/2.0;
			}
			else
			{
				shusband=1.0/4.0;
			}
			shusband=shusband*asset;
			residue=asset-shusband;
		}
		
		else if (wife)
		{
			//swife denotes total share of all wives
			if (!son && !daughter && !gson && !gdaughter)
			{
				swife=1.0/4.0;
			}
			else
			{
				swife=1.0/8.0;
			}
			swife=swife*asset;
			residue=asset-swife;
		}


	//father

	if (father)
	{
		
		if (son || daughter || gson || gdaughter)		
		{
			sfather=asset*1.0/6.0;		
		}
	}
	residue=residue-sfather;


	if (mother)
	{
		
		if (son || daughter || gson || gdaughter || sister || brother)		
		{
			smother=1.0/6.0;
			smother=smother*asset;			
		}
		else if (!son && !daughter && !gson && !gdaughter)
		{
			if (!father && !(husband || wife) && !sister && !brother)
			{
				smother= 1.0/3.0;
				smother=smother*asset;
			}
			else if (father || husband || wife || sister || brother)
			{
				smother=residue/3.0;
			}
		}
	}
	residue=residue-smother;
	
	//Paternal Grand Parents
	if(!father){
		if(pgfather){
			if (son || daughter || gson || gdaughter)		
			{
				spgfather=asset*1.0/6.0;				
			}
		}
		residue=residue-spgfather;
		
				
		if(pgmother && !mother){
			if(mgmother){
				spgmother = 1.0/12.0;
			}
			else{
				spgmother = 1.0/6.0;	
			}
			spgmother = spgmother*asset;
		}
		residue=residue-spgmother;
	}
		
	// Maternal Grand Parents
	if(mgmother && !mother)
	{
		if(pgmother){
			smgmother = 1.0/12.0;	
		}
		else{
			smgmother = 1.0/6.0;	
		}
		smgmother=smgmother*asset;
	}
	residue=residue-smgmother;

		//children
		if (daughter==1 && !son)
		{
			sdaughter=1.0/2.0;
			sdaughter=sdaughter*asset;
		}
		else if (daughter>1 && !son)
		{
			//sdaughter denotes share of all daughters
			sdaughter=2.0/3.0;
			sdaughter=sdaughter*asset;
		}
		else if (daughter && son)
		{
			//sson denotes share of all sons
			float temp=daughter*0.5+son*1;		//temp denotes total assets
			sdaughter=(daughter*0.5)/temp;
			sson=(son*1)/temp;
			sson=sson*residue;
			sdaughter=sdaughter*residue;
		}
		else if (son)
		{
			sson=residue;
		}
		
		residue=residue-sson-sdaughter;
/*		
		if (gdaughter==1 && !daughter)
		{
			if (!gson)
			{
				sgdaughter=1.0/2.0;
			}
			else
			{
				//sgdaughter=sgson/2.0;
			}
		}
		else if (gdaughter>1 && !daughter)
		{
			if (!gson)
			{
				sgdaughter=2.0/3.0;
			}
			else
			{
				//sgdaughter=sgson/2.0;
			}
		}
		sgson=sgson*asset;
		sgdaughter=sgdaughter*asset;
		*/
		
		if (gdaughter==1 && !gson)
		{
			sgdaughter=1.0/2.0;
			sgdaughter=sdaughter*asset;
		}
		else if (gdaughter>1 && !gson)
		{
			sgdaughter=2.0/3.0;
			sgdaughter=sdaughter*asset;
		}
		else if (gdaughter && gson)
		{
			float temp=gdaughter*0.5+gson*1;		//temp denotes total assets
			sgdaughter=(gdaughter*0.5)/temp;
			sgson=(gson*1)/temp;
			sgson=sgson*residue;
			sgdaughter=sgdaughter*residue;
		}
		else if (gson)
		{
			sgson=residue;
		}		
		residue=residue-sgson-sgdaughter;
	}
		
		
	//siblings
	if (!father && !pgfather && !son && !gson)
	{
		//gender of deceased is not considered
		if (!brother && !daughter && !gdaughter && sister==1)
		{
			ssister=residue*1.0/2.0;
		}
		else if (!sister && !daughter && !gdaughter && brother>1)
		{
			sbrother=residue;
		}
		else if (brother>1 && sister>1 && !daughter && !gdaughter)
		{
			//sbrother=ssister*2;
			float temp=sister*0.5+brother*1;		//temp denotes total assets
			ssister=(sister*0.5)/temp;
			sbrother=(sbrother*1)/temp;
			sbrother=sbrother*residue;
			ssister=ssister*residue;
		}
		else if (!brother && sister>1 && !daughter && !gdaughter)
		{
			ssister=residue*2.0/3.0;
		}
		
		
		if (!brother && sister==1)
		{
			ssister=residue*1.0/6.0;
		}
		else if (!sister && brother==1)
		{
			sbrother=residue*1.0/6.0;
		}
		else 
		{
			float temp=sister*0.5+brother*1;		//temp denotes total assets
			ssister=(sister*0.5)/temp;
			sbrother=(brother*1)/temp;
			sbrother=sbrother*residue/3.0;
			ssister=ssister*residue/3.0;
			//sbrother+ssister=1.0/3.0;		//share equally, write code accordingly
		}

	}
	if (residue>-1)
	{
		
		if (father)
		{
			
			if (son || daughter || gson || gdaughter)		
			{
				if (!son && !gson)
				{
					sfather=sfather+residue;
				}			
			}
			else
			{
				sfather=residue;
			}
		}
		
		if(!father){
			if(pgfather){
				if (son || daughter || gson || gdaughter)		
				{
					if (!son && !gson)
					{
						spgfather=spgfather+residue;
					}			
				}
				else
				{
					spgfather=residue;
				}
			}
			residue=residue-spgfather;
		}
	}
	
	//OUTPUTS!!!
	cout << "Shares of all concerned are as follows:"<<endl;
	if(husband){
		cout << "Share of husband is:"<<shusband<<endl;	
	}
	if(wife){
		cout << "Share of each wife is:"<<swife/wife<<endl;	
	}
	if(son){
		cout << "Share of each son is: "<<sson/son<<endl;
	}
	if(daughter){
		cout << "Share of each daughter is: "<<sdaughter/daughter<<endl;
	}
	if(gson){
		cout << "Share of each grand son is: "<<sgson/gson<<endl;
	}
	if(gdaughter){
		cout << "Share of each grand daughter is: "<<sgdaughter/gdaughter<<endl;
	}
	if(father){
		cout << "Share of father is: "<<sfather<<endl;
	}
	if(mother){
		cout << "Share of mother is: "<<smother<<endl;
	}
	if(pgfather){
		cout << "Share of pateral grandfather is: "<<spgfather<<endl;
	}
	if(pgmother){
		cout << "Share of paternal grandmother is: "<<spgmother<<endl;
	}
	if(mgmother){
		cout << "Share of maternal grandmother is: "<<smgmother<<endl;
	}
	if(brother){
		cout << "Share of each brother is: "<<sbrother/brother<<endl;
	}
	if(sister){
		cout << "Share of each sister is: "<<ssister/sister<<endl;
	}

	if(residue<=-1)
	{
		cout<<"All shares exceed total amount."<<residue<<"needs to be subtracted from all share holders according to rules"<<endl;
	}

	return 0;
}
