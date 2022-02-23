#include <iostream>
#include <fstream>
#include <vector>

#define NELMS(array) (sizeof array) / sizeof (array[0])
const int LETTER_z = 122;
const int LETTER_a = 97;
// Globals
int nelms;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;


// ReadFile pass filename (string format) return ifstream object)
ifstream ReadFile(string filename)
{
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return ifstream(NULL);
    }

    return input_file;
}
// check_bytes refactored by ide
static void check_bytes(int &a, const vector<char> &bytes, char &c, char *ch) {
    for (const auto &i : bytes) {
        if (isalpha(i)) {
            c = tolower(i);
            a = nelms-(LETTER_z-int(c));
            ch[a]++;
        }
    }
}
//readbytes refactored by ide
static void readbytes(char *ch) {
    for (int x = 0; x <= nelms;x++) {
        ch[x]=0;
    }
}

// create_histogram pass ifstream to function return ??
char * create_histogram_array(ifstream & file){
    vector<char> bytes;
    char byte = 0;
    char c;
    static char ch[26];
    while (file.get(byte)) {
            bytes.push_back(byte);
    }
    nelms = NELMS(ch)-1;
    readbytes(ch);
    int a = 0;
    check_bytes(a, bytes, c, ch);
    return ch;
}

void print_histogram(char arr[], int n){
    cout << "  " << "123456789012345678901234567890" << endl;
    cout << "  " << "------------------------------" << endl;
    for (char i = 0; i <= n; i++) {
       int count = arr[i];
       char letter=(char)(i+LETTER_a);
       cout << letter << "|";
       for (char j = 0; j < count; j++)
             cout << "*";
       cout << "\n";
    }
 }

int main()
{
    string filename("/Users/williamcrupi/Documents/github/cplus/histogram/infiles/input.txt");
    
    ifstream file_read = ReadFile(filename);
    char * ptr_histogram_array;

    ptr_histogram_array = create_histogram_array(file_read);
    print_histogram(ptr_histogram_array, nelms);
    cout << endl;
    file_read.close();
    return EXIT_SUCCESS;
}
