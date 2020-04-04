// http://www.cplusplus.com/doc/oldtutorial/templates/


using namespace std;

template <class T>
class GenStack {
	
	public:
		// CONSTRUCTORS
		GenStack();	// Default constructor
		GenStack(int maxSize);	// Overloaded constructor
		void init(int maxSize);	// Internal method called by constructors
		~GenStack();	// Destructor
		
		
		// CORE FUNCTIONS
		void push(T data);	// Insert
		T pop();	// Remove
		
		
		// AUXILIARY FUNCTIONS
		bool isFull();
		bool isEmpty();
		T peek();
		int size();
		void printStack();
	
		int top;	// Keep track of indices representing top of stack


	private:
		// MEMBER VARIABLES
		static const int DEF_MAX;	// Default maximum array size
		
		int mSize;	// Max size of myStack
		
		T *myArray;
		
		// INTERNAL FUNCTIONS
		void resize(int sizeChange);
	
};