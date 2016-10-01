/*      Name: TF_IDF.c
        Purpose: Uses term frequency-inverse document frequency (TF-IDF) technique to determining which strings are most relevant to a given query. This technique mitigates common word's contribution to relevance scores by weighting each term's frequency by a factor called the inverse document frequency.
        Author: Sandra Papo     */

#include <stdio.h>
#include <math.h>
#include <string.h>

double idf(const char T[], const char *D[], int N);
int tf(const char T[], const char di[]);

int main(void)
{
    //intput
    int N = 3;
    const char *D[N];
    D[0] = "this sentence is about ducks";
    D[1] = "this sentence is about dogs";
    D[2] = "dogs dogs dogs";
    const char T[] = "dogs";

    // for loop to calculate and print all input values
    for (int i = 0; i < N; i++) {
        double final = tf(T, D[i]) * idf(T, D, N);// formula computation
        printf("%i: %f\n",i + 1, final);//prints answer
    }
    	return 0;
}

// returns the number of times the term T appears in document/sentence di
int tf(const char T[], const char di[]) {
    
    int occurrences = 0; // initialize occurances count to 0
    const char *ptr, *lastfind = NULL; //pointer initialization
    
    //for loop (sets pointer to given sentence; runs while last found term = first occurance of term in sentence; set pointer to 1 term after last find of the sentence)
    for(ptr=di; (lastfind=strstr(ptr, T)); ptr=lastfind+1){
        occurrences++;// counts
    }
    return occurrences;
}

//  returns the log of the total number of documents divided by the number of documents which contain term T. Note that this is constant across all documents for a given T
double idf(const char T[], const char *D[], int N) {

    //loop finds number of documents that contain the term T (docCount)
    double docCount = 0;
    for (int i = 0 ; i < N ; i++ ) {
        double wordCount = tf(T,D[i]);
        if (wordCount > 0) {
            docCount++;
        }
        
    }
    double totalDoc = N;//Total documents
    double idf = log10(totalDoc/ docCount);//Calculation
    return idf;
}
