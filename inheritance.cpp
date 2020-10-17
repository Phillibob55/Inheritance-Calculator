#include<iostream>
#include<string>
using namespace std;

int main(){
	
	//Declarations
	char gender;
	char temp;
	bool married;
	double noOfChildren, son, daughter;
	double shareofDaughter, shareofSon, totalShares, paisa;
	
	cout << "Net worth of the deceased(After paying debts and due expenditures): ";
	cin >> paisa;
	
	
	cout << "Male(m) or Female(f): ";
	cin >> gender;
	
	//Marrital Status
	cout << "Is the deceased married(t/f)? ";
	cin >> temp;
	if(temp == 't'){
		married = true;
	}
	else if(temp == 'f'){
		married = false;
	}
	
	//Primary heirs
	if(married == true){
		cout << "How many children does the deceased have?";
		cin >> noOfChildren;
		if(noOfChildren != 0){
			cout << "How many of the children are boys? ";
			cin >> son;
			cout << "How many of the children are girls?";
			cin >> daughter;
		}
	}
	
	//Children of the Deceased
	if(daughter == 1 && son == 0){
		shareofDaughter = 1;
		totalShares = 2;
		cout << "Share of the daughter: " << shareofDaughter / totalShares << endl;
		cout << "Which is worth about " << (shareofDaughter / totalShares) * paisa << endl;
	}
	else if(daughter >= 2 && son == 0){
		totalShares = paisa * (2.0/3.0);
		cout << "Total money for each daughter is " << (totalShares / daughter)<< endl;
		
	}
	else if(daughter >= 1 && son >= 1){
		shareofDaughter = 1;
		shareofSon = 2;
		totalShares = (shareofSon * son) + (shareofDaughter * daughter);
		cout << "Share of Each son: " << shareofSon / totalShares << endl;
		cout << "Which is worth about " << (shareofSon / totalShares) * paisa << endl;
		cout << "Share of Each daughter: " << shareofDaughter / totalShares << endl;
		cout << "Which is worth about " << (shareofDaughter / totalShares) * paisa << endl;
	}
	else if(daughter == 0 && son >= 1){
		totalShares = 1;
		shareofSon = 1.0 / son;
		cout << "Share of Each son: " << shareofSon / totalShares << endl;
		cout << "Which is worth about " << (shareofSon / totalShares) * paisa << endl;
	}
	
	
	
	//Second heirs
	
	
	return 0;
}


/*
	if(married == true){
		cout << "\nIs the deceased's spouse alive(y/n)? ";
		cin >> temp;
		if(temp = 't'){
			if(gender == 'f'){
				
			}
		}
	}
*/	

