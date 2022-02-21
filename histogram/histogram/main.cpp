#include <iostream>
#include <fstream>
#include <vector>

#define NELMS(array) (sizeof array) / sizeof (array[0])
const int LETTER_Z = 122;
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
    for (int x = 0; x <= nelms;x++) {
        ch[x]=0;
    }
    int a = 0;
    for (const auto &i : bytes) {
        if (isalpha(i)) {
            c = tolower(i);
            a = nelms-(LETTER_Z-int(c));
            ch[a]++;
        }
    }
//    for (int x = 0; x <= nelms ;x++) {
//        printf("%d ",ch[x]);
//    }
//    printf("\n");
    return ch;
}
int main()
{
    string filename("/Users/williamcrupi/Documents/github/cplus/histogram/infiles/input.txt");
    
    ifstream file_read = ReadFile(filename);
    char * ptr_histogram_array;
    
    ptr_histogram_array = create_histogram_array(file_read);
    for (int x = 0; x <= nelms ;x++) {
        printf("%d ",ptr_histogram_array[x]);
    }
    printf("\n");
    cout << endl;
    file_read.close();
    return EXIT_SUCCESS;
}
