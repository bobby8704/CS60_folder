// Several functions demonstrating use of pointers, separated into 4 lessons: 
// 1. Examples of using & to access variables' addresses, 
//    using * to declare variables of pointer type, and 
//    using * to dereference pointers (access the values they point to). 
// 2. Learn about pointer arithmetic and how to use arrays as pointers. 
// 3. Practice memory diagrams for pass-by-reference and pass-by-pointer.
// 4. Learn how to use new and delete with pointers to access heap memory.
//
// Most of the code in this program is output to the console and several calls
// to a utility function waitForUser() effectively pauses execution so main,
// which is separated into four lessons divided by helper functions, can be run/
// presented like a slideshow.
//
// Sara Krehbiel, 10/16/24

#include <iostream>

using namespace std;

void waitForUser(); // utility function used throughout to stall the program

void pointersToLocalVariables(); // Lesson 1
void staticArraysAsPointers(); // Lesson 2
void passByRefVsPassByPointer(); // Lesson 3
void usingTheHeap(); // Lesson 4

// can run these four functions sequentially or individually
int main() {
  //pointersToLocalVariables(); 
  //staticArraysAsPointers();
  passByRefVsPassByPointer(); 
  //usingTheHeap();
}

// 1. Using & and * for accessing addresses and using pointers on the stack
void pointersToLocalVariables() {
  cout << "\nLESSON 1: Using & and * for pointers on and to the stack\n\n";
  int ignore;

  // ACCESSING THE ADDRESS OF YOUR VARIABLES:
  cout << "& gets the address of a variable:\n";

  int a = 2;
  double b = 3.5;
  int c = 4;

  {
    cout << "\nint a = 2;\ndouble b = 3.5;\nint c = 4;\n\n";
  } // braces used here only to suppress couts of code

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;

  // note: the first variables go on the bottom of the stack
  //       and the smallest addresses are on top
  cout << "&a: " << &a << endl; 
  cout << "&b: " << &b << endl;
  cout << "&c: " << &c << endl;
  
  cout << "\nsizeof(a)=" << sizeof(a) << "; sizeof(b)=" << sizeof(b) << endl;

  waitForUser();

  // DECLARING POINTER VARIABLES:
  cout << "* modifies type so int *p holds an address of an int:\n";

  double* bptr = &b; // This spacing is allowed but ill-advised
  int *aptr = &a, *cptr = &c, d = 7; // Note: * binds to the variable, not int
  //bptr = &c; // ERROR: incompatible types
  //&a = aptr; // ERROR: &a is an r-value; can't reassign where variables live
               // Analogous to f.getDenom() = 4 vs  int d = f.getDenom()

  {
    cout << "\ndouble* bptr = &b;\nint *aptr = &a, *cptr = &c, d = 7;\n\n";
  }

  cout << "aptr: " << aptr << endl;
  cout << "bptr: " << bptr << endl;
  cout << "cptr: " << cptr << endl;

  cout << "&aptr: " << &aptr << endl;
  cout << "&bptr: " << &bptr << endl;
  cout << "&cptr: " << &cptr << endl;

  cout << "\nsizeof(aptr)=" << sizeof(aptr) << "; sizeof(bptr)=" << sizeof(bptr) << endl;

  waitForUser();

  // DEREFERENCING POINTERS:
  cout << "* gets the value that an already-initialized pointer addresses:\n\n";

  cout << "*aptr: " << *aptr << endl;
  cout << "*bptr: " << *bptr << endl;
  cout << "*cptr: " << *cptr << endl;

  waitForUser();

  // USING ADDRESS AND DEREFERENCING OPERATORS IN ASSIGNMENT
  cout << "As variables, pointers can be reassigned:\n";

  c = *aptr;
  c++;
  cptr = aptr;
  aptr = &c;
  *bptr *= 3; // If b has value 3.5, this is the same as *bptr = 10.5;
  //*aptr = 12; // reassigns the value of the thing aptr points to (here c)
  //a = &c; // ERROR: a points to an int, not an int pointer

  {
    cout << "\nc = *aptr;\nc++;\ncptr = aptr;\naptr = &c;\n*bptr *= 3;\n";
    cout << "\nDraw memory diagrams to trace the effect of this!\n";
    waitForUser();
  }

  cout << "Note that the addresses of local variables never change,\n\n";

  cout << "&a: " << &a << endl;
  cout << "&b: " << &b << endl;
  cout << "&c: " << &c << endl;
  cout << "&aptr: " << &aptr << endl;
  cout << "&bptr: " << &bptr << endl;
  cout << "&cptr: " << &cptr << endl;

  waitForUser();

  cout << "but you can update values, including where pointers point,\n\n";
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << "aptr: " << aptr << endl;
  cout << "bptr: " << bptr << endl;
  cout << "cptr: " << cptr << endl;

  waitForUser();
  
  cout << "and value updates are reflected when you dereference pointers.\n\n";
  cout << "*aptr: " << *aptr << endl;
  cout << "*bptr: " << *bptr << endl;
  cout << "*cptr: " << *cptr << endl;

  cout << "\nEND OF LESSON 1.\n";
}

// 2. Arrays as pointers
void staticArraysAsPointers() {
  cout << "\nLESSON 2: Understanding (static) arrays as pointers\n\n";

  cout << "If you cout an array, it looks like an address,\n\n";

  double a[] = {1.5, 2.5, 3.5};

  {
    cout << "double a[] = {1.5, 2.5, 3.5};\n\n"; 
  }

  cout << "a: " << a << endl; 

  waitForUser();

  cout << "because arrays ARE pointers!\n\n";

  double *p = a; 

  {
    cout << "double *p = a;\n\n";
  }

  cout << "p: " << p << "\n";

  waitForUser();

  cout << "An array's value is its address, pointing to its first element:\n\n";

  cout << "a:  " << a << endl;
  cout << "&a: " << &a << endl; 
  cout << "*a: " << *a << endl;
  cout << "p:  " << p << endl;
  cout << "&p: " << &p << endl; 
  cout << "*p: " << *p << endl;

  //double *q = &a; // ERROR: a and &a have the same value but different types

  waitForUser();

  cout << "Differentiated pointer types enable pointer arithmetic:\n\n";

  double *last = p+2; 
  double *onePast = p+3; // NOTE: No warning, despite being out of bounds

  {
    cout << "double *last = p+2;\n";
    cout << "double *onePast = p+3; // out of bounds, but allowed\n\n";
  }

  cout << "last:     " << last << endl;
  cout << "onePast:  " << onePast << endl;
  cout << "*last:    " << *last << endl;
  cout << "*onePast: " << *onePast << endl;
  //cout << "a[3] =    " << a[3] << " // WARNING: [] does bounds checking\n";

  waitForUser();

  cout << "Can print an array using pointer arithmetic,\n\n";

  {
    cout << "for (int i=0; i<3; i++) cout << *(a+i) << \" \";\n\n";
  }

  for (int i=0; i<3; i++) 
    cout << *(a+i) << " "; // NOTE: a[i] is defined as *(a+i)

  cout << "\n\nand can use [] with a pointer to access array contents.\n\n";

  {
    cout << "for (int i=0; i<3; i++) cout << p[i] << \" \";\n\n";
  }

  for (int i=0; i<3; i++)
    cout << p[i] << " ";
  cout << endl;

  cout << "\nEND OF LESSON 2.\n";
}

// 3. Memory diagrams for functions with arrays/pointers and references
void arrayParam(int arr[]);
void foo(int arr[], int size, int& sum);
void bar(int *arr, int size, int* sum);
void passByRefVsPassByPointer() {
  cout << "\nLESSON 3: Functions using pointers and references\n\n";

  cout << "Though often bad practice, sizeof tells a static array's size,\n\n";

  int a1[] = {5,0,1};

  {
    cout << "int a1[] = {5,0,1};\n\n";
  }

  cout << "a1 = " << a1 << endl;
  cout << "sizeof(a1) = " << sizeof(a1) << endl;
  cout << "sizeof(a1)/sizeof(a1[0]) = " << sizeof(a1)/sizeof(a1[0]) << endl;

  cout << "\nbut this doesn't work for arrays passed into functions:\n\n";

  {
    cout << "arrayParam(a1);\n\n";
  }

  arrayParam(a1);

  cout << "because they are passed in as pointers.\n";

  waitForUser(); 

  cout << "Parameters can also be declared as references:\n\n";
  
  {
    cout << "int a2[] = {1,2,3,4};\nint sum = 0;\n";
    cout << "foo(a2,sizeof(a2)/sizeof(a2[0]),sum);\n\n";
  }

  int a2[] = {1,2,3,4};
  int sum = 0;
  foo(a2,sizeof(a2)/sizeof(a2[0]),sum);

  cout << "sum after function call: " << sum << endl;

  for (int i=0; i<4; i++) {
    cout << *(a2+i) << " ";
  }
  cout << endl;

  waitForUser();

  cout << "You can also pass pointers explicitly:\n\n";

  {
    cout << "int *p = &sum;\nbar(a1,3,p);\n\n";
  }

  int *p = &sum;
  bar(a1,3,p);

  cout << "sum = " << sum << "\na1: ";
  for (int i=0; i<3; i++) {
    cout << a1[i] << " ";
  }
  cout << "\n\nEND OF LESSON 3.\n";
}

// shows why sizeof method can't find #elems in an array passed into a function
void arrayParam(int a[]) {
  {
    cout << "void arrayParam(int a[]) {\n  // WARNING: a is now an int*\n";
  }
  cout << "  a = " << a << endl;
  // WARNING: sizeof(a) is the size of an int *
  //cout << "  sizeof(a)/sizeof(a[0]) = " << sizeof(a)/sizeof(a[0]) << "\n"; 
  cout << "  *a = " << *a << endl;
  cout << "  a[1] = " << a[1] << "\n}\n\n";
}

// increments entries in arr and adds original values to sum (passed-by-ref)
void foo(int arr[], int size, int& sum) { 
  {
    cout << "void foo(int arr[], int size, int& sum) {\n";
    cout << "  cout << \"sum during foo: \" << sum << endl;\n";
    cout << "  for (int i=0; i<size; i++) sum += arr[i]++;\n}\n\n";
  }
  cout << "sum during foo: " << sum << endl;
  for (int i=0; i<size; i++) {
    sum += arr[i]++;
  }
}

// increments entries in arr and adds original values to sum (passed-by-pointer)
void bar(int *arr, int size, int* sptr) { 
  {
    cout << "void bar(int *arr, int size, int* sptr) {\n";
    cout << "  for (int i=0; i<size; i++) *sptr += (*(arr+i))++;\n}\n\n";
  }
  for (int i=0; i<size; i++) {
    *sptr += (*(arr+i))++; // NOTE: parens are important here
  }
}

// 4. Using pointers with new and delete to access heap memory
int *getSquareArray(int);
void usingTheHeap() {
  cout << "\nLESSON 4: Using pointers to access heap memory\n\n";

  cout << "Use \'new\' to allocate memory on the stack:\n\n";

  int stackInt = 4; // a named local variable for an int on the stack
  int *stackIntP = &stackInt; // a pointer on the stack to a 
  int *heapIntP = new int(3); // pointer the int itself is anonymous

  {
    cout << "int stackInt = 4;\n";
    cout << "int *stackIntP = &stackInt;\n";
    cout << "int *heapIntP = new int(3);\n";
  }

  waitForUser();

  cout << "stackInt:   " << stackInt << endl;
  cout << "&stackInt:  " << &stackInt << endl << endl;
  cout << "stackIntP:  " << stackIntP << endl;
  cout << "&stackIntP: " << &stackIntP << endl;
  cout << "*stackIntP: " << *stackIntP << endl << endl;
  cout << "heapIntP:   " << heapIntP << endl;
  cout << "&heapIntP:  " << &heapIntP << endl;
  cout << "*heapIntP:  " << *heapIntP << endl;

  waitForUser();

  cout << "Use \'delete\' to avoid orphaning heap memory:\n\n";

  delete heapIntP; // Your code will be functional without this,
  heapIntP = stackIntP; // but then this would orphan your 3.

  {
    cout << "delete heapIntP; // Your code will be functional without this,\n";
    cout << "heapIntP = stackIntP; // but then this would orphan your 3.\n";
  }

  waitForUser();

  cout << "This is particularly relevant for arrays on the heap:\n\n";

  cout << "How many ints in your dynamically-allocated array? size = ";
  int size;
  cin >> size;

  int *a = new int[size];

  {
    cout << "\nint *a = new int[size];\n\n";
  }

  cout << "Enter " << size << " ints: ";  
  for (int i=0; i<size; i++) {
    cin >> a[i];
  }

  cout << "How many more? extra = ";
  int extra;
  cin >> extra;

  int *tempPtr = new int[size+extra]; 

  {
    cout << "\nint *tempPtr = new int[size+extra];\n\n";
  }

  cout << "Enter " << extra << " more: ";

  for (int i=0; i<size+extra; i++) {
    if (i<size) {
      tempPtr[i] = a[i];
    } else {
      cin >> tempPtr[i];
    }
  }

  cout << "a contents: ";
  for (int i=0; i<size; i++) {
    cout << a[i] << " ";
  }
  cout << "\ntempPtr contents: ";
  for (int i=0; i<size+extra; i++) {
    cout << tempPtr[i] << " ";
  }
  cout << "\na: " << a << "\ntempPtr: " << tempPtr << endl;

  waitForUser();

  cout << "Use delete [] to get free old memory before updating pointers:\n\n";

  delete [] a;
  a = tempPtr;
  tempPtr = nullptr;

  {
    cout << "delete [] a;\na = tempPtr;\ntempPtr = nullptr;\n\n";
  }

  cout << "a: " << a << endl;
  cout << "tempPtr: " << tempPtr << endl;
  cout << "a contents: ";
  for (int i=0; i<size+extra; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  waitForUser();

  cout << "By allocating heap memory, we can now return arrays:\n\n";

  {
    cout << "int *squares = getSquareArray(4);\n\n";
  }
  
  int *squares = getSquareArray(4);
  for (int i=0; i<4; i++) {
    cout << squares[i] << " ";
  }
  cout << endl;
  
  delete [] squares;
  squares = nullptr;

  {
    cout << "delete [] squares;\nsquares = nullptr;\n";
  }

  waitForUser();

  cout << "Finally, note that dereferencing a nullptr causes a segfault:\n\n";

  {
    cout << "int dereferencedVal = *squares; // compiles fine but segfaults\n";
    cout << "cout << dereferencedVal << endl; // so we never get here\n\n";
  }

  int dereferencedVal = *squares; // RUNTIME ERROR
  cout << dereferencedVal << endl; // this code isn't reached
}

int* getSquareArray(int size) {
  {
    cout << "int* getSquareArray(int size) {\n";
    cout << "  int *a = new int[size];\n";
    cout << "  for (int i=0; i<size; i++) a[i]=i*i;\n  return a;\n}\n\n";
  }
  int *a = new int[size];
  for (int i=0; i<size; i++) {
    a[i] = i*i;
  }
  return a;
}

// stalls program excecution until user enters a non-whitespace input
void waitForUser() {
  cout << "\nContinue (y/n)? ";
  string uInput;
  cin >> uInput;
  if (toupper(uInput[0])=='N') exit(1);
  cout << endl;
}

