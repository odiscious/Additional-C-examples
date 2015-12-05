
class PiggyBank{

public:
	PiggyBank();
	~PiggyBank();
	PiggyBank(PiggyBAnk &); //implicit Copy constructor is good enough because, 
	PiggyBank(int pennies, int nickels, int dimes, int quarters, int halfDollar);
	void CombineBanks(PiggyBank &);
	double getCurrentBankValue() const ;
	
	int getPennies() const;
	int getNickels() const;
	int getDimes() const;
	int getQuarters() const;
	int getHalfDollar() const;
	bool isFull() const;
	
	void setPennies(const int pennies);
	void setNickels(const nickels);
	void setDimes(const dimes);
	void setQuarters(const  quarters);
	void setHalfDollar(const halfDollar);
	
	//verbs
	bool AddPennies(const int &);
	bool AddNickels(const int &);
	
	int EmptyBank(int &, int &, int &, int &, int &); //returns the total amount that was in the bank
	
	//Note: *(arr1+3) what does this do?
	//base case P(0) or P(1) is true
	//Then P(k) or P(k-1) 
	//prove (7^n-1) is divisible by 6  P(1) = true 
	//P(k-1) 7^k-1 - 1 = 6x assumed start here and modify to look like the one below
	//prove P(k) 7^k - 1 ==> 
	//prove base case
	//assume k - 1
	//7(7^k-1 - 1) = 7(6x)
	//7k-1-6 = 6(7x)
	//7^k - 1 = 6(7x) + 6
	
private:
int pennies;
int nickels;
int dimes;
int quarters;
int halfDollar;
double total;
bool isFull;
};

int main()
{
	
	PiggyBank b1(1,2,3,4,5); // not calling copy constructor
	PiggyBank b2 = b1; // yes, Copy Constructor is called!
	
	return 0;
}