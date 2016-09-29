#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "quadgram.h"

#define TEMP 20
#define STEP 0.2
#define COUNT 10000

char *playfairDecipher(char *key, char *in,char *out, unsigned long len);
float playfairCrack(char *text,unsigned long len, char* maxKey);
double scoreTextQgram(char *text,unsigned long len);

int main(int argc, char *argv[]) {
    extern float quadgram[];

    char cipher[]  = "KXLHRMYZEZDXYGMXERYGNUZHORBTXGYUXRRFKIMKTRCUSZQLDZMPATRHCUPKNGXEIQMNUBILRBMVUEXEVGXGQUTEMKTUPKRGXKYPMNRZISIQHDDTRMMNPWXEFENVRZXHMKTRCUZLBKYGQUGNKRYDCPDYCLEMRHCUPKNGXEIQMNXRMKILIRMWMVPCQRZDKNXDCMRHCUPKBGQRXRQRZDMKTRCUALRIQYZDGRBKSZSLDTCFQTRHCUPKIDMNZYQYRUGNNMQUXLXEDINMGLMYDEBKXVXKMKMUZCRCXKGNNMXGQZILIXZSYMKNYNRMXRKNXDSZWYRXVTRIEWRHCUXDKIIKMDNBKNYXRXHBZHZXPKZDGXCUULZENGQRXRQZGRYGCEIQRHLCQRXRKNWGQUCPXRHNZHXDSZDTQUXLXEDINMUXRHTYXVKNWGYVMYREZOCIYIHDDTRMMNPWXEFENVRZXHKNGNNBYNRMOBBMXGHDCRULERBKBUQUXLXEYIDINMULRHMYLKCQONPWQRURRHKNYXKMRHCUHNMUXKNMMKTRCUHNAMOMQEIRQRZKMKTRCUHNMUIQXDSZDTMYACOGEXFEYIHDDTULRHZXKPUBXRKNWXNBCZIMMHXKWNXCCLXKQUXLXEQZBKQUXLXEYIVZXEXKKZYGBMQUMYUEXEDZHIACILXVDZDTXDSINMULERBKZLKPILXVHZTICIYGYGQUGXGNKRYDWTPCCXLMQUMYUEXEDZYIDZDTXDSDBRNBCZQYUEXEDSXCHDKPBKDZDTDZWMRHCUPKOSUEXEQGRHCUGLMYPKLQZIXKGYXKQIBUXDRZYGEGRXPKBEXDSZDYZIRQRGMKTRCUXRHAIQGYZXPKZDYPMNKLSZKPCZXDKNYTEZDXYGMKTRCUMYRXRAUNKTRHCUYGUEGYUXRIZOXCNMQRZKGREUIVHDDTMKTRCUPKOSUEXEQGRHCUQIZGXDCGQUMYAQNBDZKIIHMNKLUZFQRMEULFRKAXDXDTXDMYRCZHEGMKTRCUKLSZDYKNMYUEXEVGQRDXCFQVRMDTPKKGFEIRNGNMQRKFIONMCIKXEUIXKUURWFUPMSCXEMRHCUCPEABDVYUEXEQZQZMKTUIECRXYKNYTEZDXYGMKTRCUMYXDDEDTBUSRVGLZACBKZUGRXVMKTRCUSZQLHZTYQRPOAKPUEWNBCXYGPKOIXCEXIQSRYZEFQAKLXDCWCEXKNVZQMXNBCIXORXQLOGPKKNYPMYXKLCZXPKZDGNNMMQRLRXEISNNMBNGWQRKTRHCUBROGPKMKTRCUHNZHCPXMBUAWRHCUPKIZILFWBRRBGBNMCLMBXYDNMYRXFKRMCPXNUXRIZOIKNMQUXLXEDINMPFNBMVRHMYRLRLFXPKPCRDBNUWPCCXIHQUYIVIBMXVKZTBIKEFZMSRDTKNWNSXBHREKLTSRMXUUEKNBKNMBUMKMUQILSLKRLXKGRLEDTPFMYXCMBHDDTDINMXGCFDZXKDEDYMKBPZHIKCRMKTRCUHNAOBNGBNMBNGWQRBKNMDZDTXDMSZDHBEGACTPAXUEXDCWKMRHLAURTWQRQAILEFEMRHCUPKIDZMCIYGXDCWQRZLIHWXBMCFXOXDSDBUPKUFUXKUMQXDCIUEMYHACEIKNMMVXKLGZQHNPOSZQILHIKPCRXCUHDPLZLQADNNYKUKPYPMNXOXQVZEXGONMKNCPDZKIMNZXPKZDGNNMXGZDMNBRBMMKTRCUBROGPKCLILRVFQXCQUMNQLEUCZXDMKTRCULZHNZONBWTXDNIKNGYXDSDZLIHYPWGBRXDIQBHRXZCZEKTRHCUXDUQZSVUFEQIYPMNMYZDGXCRKNWCXRPCHZXUXEQINBMYXAUEMNPWQRUPIZXKQAKNYXRXHBZHBRBIZKNXACXMQRZLXRKLSZDYMNMEQTRHCUPKOSZQMNKLIRKNPMKNMYUEXEDINMMKXYXDZRDTKNGXVGXAYPMYLCXDKNGVPKIZVGXAYPMYIKNRRUMKTRCUPKIZBNBNMKTRCUEGIRPKIKMYLCXDKNGVBUMYLKZSULNBGNNRRUKNCPBKXZBRZDQROZTYQRWFNRRUBNMKTRCUKZQYXGLDICHNMUFUIONBZPXPXNMYXDCMRHCUEGPKYPMYXDONPWQUWXXDIKNMPKIZPKIZROMKTRCUCLILEWRHCUCLILIWXCNBMNMYAQORUMQGRHCUPKKGQUKTREGNNMDZDTDINMPKIZIZNIBIIKZIBIIKZIBIIKZIBIIKZIBIIKZIBIIKAQRHCUGXILXBBMEZTWQRUMIRURPWQRHARLXKYDFQRLIKNMBNGWQRKTRHCUMQRUZHXGZDMYRIZQYPWGBRXDIQXRAXPCIKMKTRCUHNAOBNGBNMCIKXEUEWORUMQZBKQRIZNIBIIKZIBIIKZIBIIKZIBIIKZIBIIKZIBIIKRLIKMKTRCUGXILXBBMQRZDMYRXFRRXBUMYAKARXKYDFQRLIKNMPKOSUEXEYDLQRXQIIQMVPCPKZQQYREHGCEXDMDUVRGQIFWMKTRCUPKOSBMQRZDPKBNSXDTFENMBUAXNUIRMVNBLQRXIZOSRGPKVYUETR";
    unsigned long len = strlen(cipher);
    char *out = malloc(sizeof(char)*(len+1));
    srand((unsigned)time(NULL));

    char key[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int i=0;
    double score,maxscore=-99e99;
    while(1) {
        i++;
        score = playfairCrack(cipher,len,key);
        if(score > maxscore) {
            maxscore = score;
            printf("Score: %f\n", score);
            printf("Count: %d\n", i);
            printf("Key: '%s'\n", key);
            playfairDecipher(key, cipher, out, len);
            printf("Plaintext: '%s'\n", out);
        }
    }
    return 0;
}

void exchange2letters(char *key) {
    int i = rand()%25;
    int j = rand()%25;
    char temp = key[i];
    key[i]= key[j];
    key[j] = temp;
}

void swap2rows(char *key) {
    int i = rand()%5;
    int j = rand()%5;
    char temp;
    int k;
    for(k=0;k<5;k++) {
        temp = key[i*5 + k];
        key[i*5 + k] = key[j*5 + k];
        key[j*5 + k] = temp;
    }
}

void swap2cols(char *key) {
    int i = rand()%5;
    int j = rand()%5;
    char temp;
    int k;
    for(k=0;k<5;k++) {
        temp = key[k*5 + i];
        key[k*5 + i] = key[k*5 + j];
        key[k*5 + j] = temp;
    }
}

void modifyKey(char *newKey,char *oldKey) {
    int k,j,i = rand()%50;
    switch(i) {
        case 0: strcpy(newKey,oldKey); swap2rows(newKey); break;
        case 1: strcpy(newKey,oldKey); swap2cols(newKey); break;
        case 2: for(k=0;k<25;k++) newKey[k] = oldKey[24-k]; newKey[25] = '\0'; break;
        case 3: for(k=0;k<5;k++) for(j=0;j<5;j++) newKey[k*5 + j] = oldKey[(4-k)*5+j];
            newKey[25] = '\0';
            break;
        case 4: for(k=0;k<5;k++) for(j=0;j<5;j++) newKey[j*5 + k] = oldKey[(4-j)*5+k];
            newKey[25] = '\0';
            break;
        default:strcpy(newKey,oldKey);
            exchange2letters(newKey);
    }
}

float playfairCrack(char *text,unsigned long len, char* bestKey) {
    int count;
    float T;
    char *deciphered = malloc(sizeof(char) * (len+1));
    char testKey[26];
    char maxKey[26];
    double prob,dF,maxscore,score;
    double bestscore;
    strcpy(maxKey,bestKey);
    playfairDecipher(maxKey,text,deciphered,len);
    maxscore = scoreTextQgram(deciphered,len);
    bestscore = maxscore;
    for(T = TEMP; T >= 0; T-=STEP) {
        for(count = 0; count < COUNT; count++) {
            modifyKey(testKey,maxKey);
            playfairDecipher(testKey,text,deciphered,len);
            score = scoreTextQgram(deciphered,len);
            dF = score - maxscore;
            if (dF >= 0) {
                maxscore = score;
                strcpy(maxKey,testKey);
            } else if(T > 0) {
                prob = exp(dF/T);
                if(prob > 1.0*rand()/RAND_MAX) {
                    maxscore = score;
                    strcpy(maxKey,testKey);
                }
            }
            if(maxscore > bestscore) {
                bestscore = maxscore;
                strcpy(bestKey,maxKey);
            }
        }
    }
    free(deciphered);
    return bestscore;
}


char *playfairDecipher(char *key, char *text, char *result, unsigned long len) {
    int i;
    char a,b;
    int a_ind,b_ind;
    int a_row,b_row;
    int a_col,b_col;

    for (i = 0; i < len; i += 2) {
        a = text[i];
        b = text[i+1];
        a_ind = (int)(strchr(key,a) - key);
        b_ind = (int)(strchr(key,b) - key);
        a_row = a_ind / 5;
        b_row = b_ind / 5;
        a_col = a_ind % 5;
        b_col = b_ind % 5;
        if(a_row == b_row) {
            if(a_col == 0) {
                result[i] = key[a_ind + 4];
                result[i+1] = key[b_ind - 1];
            } else if (b_col == 0) {
                result[i] = key[a_ind - 1];
                result[i+1] = key[b_ind + 4];
            } else {
                result[i] = key[a_ind - 1];
                result[i+1] = key[b_ind - 1];
            }
        } else if(a_col == b_col) {
            if(a_row == 0) {
                result[i] = key[a_ind + 20];
                result[i+1] = key[b_ind - 5];
            } else if(b_row == 0) {
                result[i] = key[a_ind - 5];
                result[i+1] = key[b_ind + 20];
            } else {
                result[i] = key[a_ind - 5];
                result[i+1] = key[b_ind - 5];
            }
        } else {
            result[i] = key[5*a_row + b_col];
            result[i+1] = key[5*b_row + a_col];
        }
    }
    result[i] = '\0';
    return result;
}

double scoreTextQgram(char *text,unsigned long len) {
    int i;
    char temp[4];
    double score = 0;
    for (i=0;i<len-3;i++) {
        temp[0]=text[i]-'A';
        temp[1]=text[i+1]-'A';
        temp[2]=text[i+2]-'A';
        temp[3]=text[i+3]-'A';
        score += quadgram[17576*temp[0] + 676*temp[1] + 26*temp[2] + temp[3]];
    }
    return score;
}
