/* Formula used: fn = f0 * (a)^n
 * from http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
 * fn = freq of a note n half steps away from a
 * f0 = freq of a fixed note (A4)
 * a = 2^(1/12)
 * n = #/half steps away from the fixed note
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define A4 440.0 /* fixed frequency */
#define F0 A4
#define F0_note A
#define F0_octave 4

typedef enum {C=1, Cs, D, Ds, E, F, Fs, G, Gs, A, As, B,
    END = B, HALF_STEPS_PER_OCTAVE = B 
} note_t;

double validFreqs[8][12] = {{16.35,17.32,18.35,19.45,20.60,21.83,23.12,24.5,25.96,27.5,29.14,30.87},
    {32.7,34.65,36.71,38.89,41.2,43.65,46.25,49,51.91,55,58.27,61.74},
    {65.41,69.3,73.42,77.78,82.41,87.31,92.5,98,103.83,110,116.54,123.47},
    {130.81,138.59,146.83,155.56,164.81,174.61,185,196,207.65,220,233.08,246.94},
    {261.63,277.18,293.66,311.13,329.63,349.23,369.99,392,415.3,440,466.16,493.88},
    {523.25,554.37,587.33,622.25,659.26,698.46,739.99,783.99,830.61,880,932.33,987.77},
    {1046.5,1108.73,1174.66,1244.51,1318.51,1396.91,1479.98,1567.98,1661.22,1760,1864.66,1975.53},
    {2093,2217.46,2349.32,2489.02,2637.02,2793.83,2959.96,3135.96,3322.44,3520,3729.31,3951.07}};
double validFreqs8Oct[4]={4186.01,4434.92,4698.64,4978.03};
/**
 * Generate a frequency in hz that is half_steps away from C_4
 */
double freq(note_t note, int octave_delta)
{
    double freq;
    double factor;
    double a; 
    int n;
    int octave = octave_delta - F0_octave;

    a = pow(2.0, 1.0/HALF_STEPS_PER_OCTAVE);
    n = note - F0_note;
    freq = F0 * pow(a, n);
    factor = pow(2.0, octave);
    freq = freq * factor;
    return freq;
}

int test(double freqTest, int testNote, int testOctave)
{
    if(testOctave==8)
    {
        if((validFreqs8Oct[testNote-1] - freqTest) < .01)
            return 1;
    }
    else
    {
        if(validFreqs[testOctave][testNote-1] - freqTest < .01)
            return 1;
    }
    
    return 0;
}

int main(int argc, char *argv[])
{
    /*note_t note;
    int octave_delta;

    if (argc != 3) {
        printf("Usage: %s NOTE OCTAVE_DELTA\n", argv[0]);
        return 0;
    }

    note = (note_t)(toupper(argv[1][0]) - 64);
    switch(toupper(argv[1][0])) {
        case 'A': note = A; break;
        case 'B': note = B; break;
        case 'C': note = C; break;
        case 'D': note = D; break;
        case 'E': note = E; break;
        case 'F': note = F; break;
    }
    if (note >= END) {
        fprintf(stderr, "Invalid note\n");
        return 1;
    }
    octave_delta = atoi(argv[2]);*/
    int i=0,j=0,note=0,octave=0,testsFailed=0;
    for(i=0;i<8;i++) //Test first eight octaves
        for(j=0;j<12;j++)
        {
            note = j+1;
            octave = i;
            if(test(freq(note, octave), note, octave) == 1)
                printf("Test Successful for Octave: %i Note: %i\n", octave, note);
            else
            {
                printf("Test failed for Octave: %i Note: %i\n", octave, note);
                testsFailed++;
            }
        }
    for(i=0; i<4; i++)
    {
        note = i;
        octave = 8;
        if(test(freq(note, octave), note, octave) == 1)
            printf("Test Successful for Octave: %i Note: %i\n", octave, note);
        else
        {
            printf("Test failed for Octave: %i Note: %i\n", octave, note);
            testsFailed++;
        }
    }
    printf("Tests failed: %i\n", testsFailed);
    return 0;
}

