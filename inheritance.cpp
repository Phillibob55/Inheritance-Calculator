#include<iostream>
#include<string>
using namespace std;

int main(){
	int sons = 0, daughters = 0, husband = 0, wives = 0, money = 0;
	double sharePerSon = 0.0, sharePerDaughter = 0.0, shareOfChildren = 0.0;
	double sharePerWife = 0.0, shareOfHusband = 0.0, shareOfSpouse = 0.0, moneyForSpouse = 0.0;
	double totalShares = 0.0, oneShareValue = 0.0;
	char temp, gender;
	bool children = false, married = false, spouse = false;
	
	cout << "INHERITANCE CALCULATOR!!\nBy Muhammad Luqman\nFa20/BSAI/005\nFounder, Shinzou Studios.\n";
	cout << "\n\nDisclaimer! This Calculator is programmed to distribute monetary assets among Close relatives.\n";
	cout << "This calculator also doesnot work for half siblings and distant relatives.\n\n\n";
	
	cout << "How much are the deceased's assets worth?\n";
	cin >> money;
	if(money == 0){
		cout << "Since the deceased died without any assets, Nothing needs to be distributed!\n";
		return 0;
	}
	
	//GENDER!
	cout << "What is the gender of the deceased?(m/f)\n";
	cin >> gender;
	
	//MARRITAL STATUS!
	cout << "Was the deceased Married?(y/n)\n";
	cin >> temp;
	if(temp == 'y'){
		married = true;
	}
	
	//SPOUSE!!
	if(married){
		if(gender == 'm'){
			cout << "How many Wives did the deceased leave behind?\n";
			cin >> wives;
		}
		else if(gender == 'f'){
			cout << "Is the husband Alive?(y/n)\n";
			cin >> temp;
			if(temp == 'y'){
				husband = 1;
			}
		}
	}
	
	//CHILDREN!!!!
	if(married){
		cout << "Does the deceased have children(y/n)? \n";
		cin >> temp;
		if(temp == 'y'){
			children = true;
		} 
		else{
			children = false;
		}	
		
		if(children){
			cout << "How many of the children are sons?\n";
			cin >> sons;
			cout << "How many of the children are daughters?\n";
			cin >> daughters;
			
			if(daughters == 1 && sons == 0){
				sharePerDaughter = 0.5;
			}
			else if(daughters >= 2 && sons == 0){
				sharePerDaughter = 0.6666;
			}
			else if(daughters >= 1 && sons >= 1){
				sharePerDaughter = 0.5;
				sharePerSon = 1;
			}
			else if(daughters == 0 && sons >= 1){
				sharePerSon = 1;
			}	
		}
	}
	
	//HUSBAND!
	if(husband != 0){
		if(!children){
			shareOfSpouse = 0.5;
		}
		else{
			shareOfSpouse = 0.25;
		}
	}
	
	//Wives!
	if(wives != 0){
		if(!children){
			shareOfSpouse = 0.25;
		}
		else{
			shareOfSpouse = 0.125;
		}
	}
	
	//CALCULATIONS FOR SHARES!
	if(husband = 1){
		moneyForSpouse = shareOfSpouse * money;
		money -= moneyForSpouse;
	}
	
	totalShares = (sharePerSon * sons) + (sharePerDaughter * daughters);
	oneShareValue = money / totalShares;
	
	//OUTPUT THE MONEY!!!!!!
	
	if(husband == 1){
		cout << "Share of Husband is " << moneyForSpouse << endl;
	}
	else if (wives > 0){
		cout << "Share of each Wife is " << moneyForSpouse / wives << endl;
	}
	
	if(children){
		if(sons > 0){
			cout << "Share of Each Son is " << oneShareValue* sharePerSon << endl;
		}
		if(daughters > 0){
			cout << "Share of Each Daughter is " << oneShareValue * sharePerDaughter << endl;
		}
	}
	
	return 0;
}

