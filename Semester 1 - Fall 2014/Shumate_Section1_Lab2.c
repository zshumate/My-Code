//Lab 2: ASCII-art
//Zachary Shumate
//8-26-1014
//Section 1

#include<stdio.h>

main(){
const double USDtoEUR = 0.762121;
const double USDtoGBP = 0.606101;
const double USDtoCAD = 1.092955;
const double USDtoAUD = 1.078585;
const double USDtoCNY = 6.150030;
const double EURtoGBP = 0.795364;
const double EURtoCAD = 1.433990;
const double EURtoAUD = 1.415202;
const double EURtoCNY = 8.069570;
const double GBPtoCAD = 1.803025;
const double GBPtoAUD = 1.779582;
const double GBPtoCNY = 10.150366;
const double CADtoAUD = 0.986998;
const double CADtoCNY = 5.629632;
const double AUDtoCNY = 5.703957;

double currency = 0;

printf("How much currency woud you like to convert? ");
scanf("%lf", &currency);

printf("\n\t\tUSD\tEUR\tGBP\tCAD\tAUD\tCNY\n");
printf("\n\tUSD:\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",currency,currency*USDtoEUR,currency*USDtoGBP,currency*USDtoCAD,currency*USDtoAUD,currency*USDtoCNY);
printf("\n\tEUR:\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",currency/USDtoEUR,currency,currency*EURtoGBP,currency*EURtoCAD,currency*EURtoAUD,currency*EURtoCNY);
printf("\n\tGBP:\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",currency/USDtoGBP,currency/EURtoGBP,currency,currency*GBPtoCAD,currency*GBPtoAUD,currency*GBPtoCNY);
printf("\n\tCAD:\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",currency/USDtoCAD,currency/EURtoCAD, currency/GBPtoCAD,currency,currency*CADtoAUD,currency*CADtoCNY);
printf("\n\tAUD:\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",currency/USDtoAUD,currency/EURtoAUD,currency/GBPtoAUD,currency/CADtoAUD,currency,currency*AUDtoCNY);
printf("\n\tCNY:\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf",currency/USDtoCNY,currency/EURtoCNY,currency/GBPtoCNY,currency/CADtoCNY,currency/AUDtoCNY,currency);
}
