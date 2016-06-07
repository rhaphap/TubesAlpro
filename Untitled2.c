/** PROGRAM   : tubes.c 					        */
/** DESKRIPSI : tugas besar                      	*/
/** NAMA   	  : Rizqi Hadi Prawira`         		*/
/** NIM		    : 24010315130086                      */
/** TANGGAL   : Tuesday, May 24 2016                */

/******************************* KAMUS GLOBAL ********************************/
/* header file */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
/* variable */
int Row,Col;
/* type Tabel = multi-dimensional array 3X5 of integer */
typedef int Table[3] [5];

/* Procedure Dictionary */
/* Procedure initTabel (output dataTable)
   {I.S : -}
   {F.S : dataTable is defined, 0 is element of dataTable}
   {Procces : initialisation of dataTable with 0 as element} */
void initTable(Table *dataTable);

/* Procedure loadTabel
   {I.S : dataTable, file is defined}
   {F.S : dataTable is filled with data from file}
   {Procces : filling dataTable with data from file} */
void loadTable(Table dataTable);

/* Procedure displayData
   {I.S : dataTable is defined}
   {F.S : every element is displayed in screen}
   {Procces : checking element value and display it} */
void displayData(Table dataTable);

/* Procedure maxTableValue
   {I.S : dataTable is defined}
   {F.S : maximum value of dataTable is found}
   {Procces : comparing every value to find maximum value } */
void maxTableValue(Table dataTable, int *MAX, int *RowPos, int *ColPos);

/* Procedure maxTableValue
   {I.S : dataTable is defined}
   {F.S : maximum value of dataTable is found}
   {Procces : comparing every value to find minimum value } */
void minTableValue(Table dataTable, int *MIN, int *RowPosi, int *ColPosi);

/* Procedure minRowValue
   {I.S : dataTable is defined}
   {F.S : minimum value of a row is found}
   {Procces : comparing every value in a row to find minimum} */
void minRowValue(Table dataTable, int RowPos, int *MINRow);

/* Procedure meanTableValue
   {I.S : dataTable is defined}
   {F.S : mean value is found}
   {Procces : searching for average sold goods}*/
void meanTableValue(Table dataTable, float *mean);

/* Procedure getThingNames
   {I.S : dataTable is defined}
   {F.S : the name is found}
   {Procces : checking where the value is positioned in a Row}*/
void getThingNames(Table dataTable, int RowPos);

/* Procedure getMonth
   {I.S : dataTable is defined}
   {F.S : the month is found}
   {Procces : checking where the value is positioned in a Column}*/
void getMonth(Table dataTable, int ColPos);

void menuHome();

/***************************** MAIN ALGORITHM  *******************************/
int main() {
    /** Main Dictionary**/
    Table dataTable;
    int choice;
    int MaxValue;           /* Penjualan terbanyak */
    int MinValue;           /* Penjualan terendah barang x*/
    int MinRowValue;
    int RowPos;
    int ColPos;
    float MeanValue;

    initTable(&dataTable);
    loadTable(dataTable);
    home :
        system("cls");
    menuHome();
    printf("Pilihan anda : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1: system("cls");{
          displayData(dataTable);
          getch();
          goto home;
          break;
        }
      case 2: system("cls");{
          maxTableValue(dataTable, &MaxValue, &RowPos, &ColPos);
          printf("Penjualan terbanyak pada data adalah : %d unit.\n", MaxValue);
          getThingNames(dataTable, RowPos);
          getMonth(dataTable, ColPos);
          getch();
          goto home;
          break;
        }
      case 3: system("cls");{
          minTableValue(dataTable, &MinValue, &RowPos, &ColPos);
          printf("Penjualan terendah dari data adalah : %d unit.", MinValue);
          printf("Row : %d\n", ColPos);
          getThingNames(dataTable, RowPos);
          getMonth(dataTable, ColPos);
          getch();
          goto home;
          break;
        }
      case 4:system("cls"); {
          meanTableValue(dataTable, &MeanValue);
          printf("Penjualan rata-rata keseluruhan data : %0.2f unit.", MeanValue);

          getch();
          goto home;
          break;
        }

    }
    return 0;
}

/***************************** REALISATION ***********************************/


/* Procedure initTable */
void initTable(Table *dataTable) {
    memset(*dataTable, 0, sizeof *dataTable);   /* initialize all element to 0*/
}

/* Procedure loadTable*/
void loadTable(Table dataTable){
    FILE *file;
    file=fopen("tabel.txt", "r");
    for(Row=0;Row<3;Row++)
    {
        for(Col=0;Col<5;Col++)
        {
            fscanf(file,"%d",&dataTable[Row] [Col]);
        }
    }
}

/* Procedure displayData */
void displayData(Table dataTable) {
    /* ALGORITHM */
    puts("Januari\tFeb\tMaret\tApril\tMei");
    for(Row=0;Row<3;Row++)
    {
        for(Col=0;Col<5;Col++)
        {
            printf("%d\t", dataTable[Row][Col]);
        }
        switch (Row) {
          case 0: {
            puts("Roti");
            break;
          }
          case 1: {
            puts("Sabun");
            break;
          }
          case 2: {
            puts("Pena");
            break;
          }
        }

        putchar('\n');
    }
}

/* Procedure maxTableValue */
void maxTableValue(Table dataTable, int *MAX, int *RowPos, int *ColPos){
    /* ALGORITHM */
    *MAX=dataTable[0][0];               /* */
    for(Row=0; Row<3; Row++)
    {
        for(Col=0; Col<5; Col++)
        {
            if (*MAX < dataTable[Row] [Col]) {
                *MAX = dataTable[Row] [Col];
                *RowPos = Row;
                *ColPos = Col;
            }
        }
    }
}

/* Procedure maxTableValue */
void minTableValue(Table dataTable, int *MIN, int *RowPosi, int *ColPosi) {
    *MIN=dataTable[0][0];
    for(Row=0; Row<3; Row++)
    {
        for(Col=0; Col<5; Col++)
        {
            if (*MIN > dataTable[Row] [Col]) {
                *MIN = dataTable[Row] [Col];
                *RowPosi = Row;
                *ColPosi = Col;
            }
        }
    }

}

/* Procedure minRowValue */
void minRowValue(Table dataTable, int RowPos, int *MINRow) {
    /* ALGORITHM */
    Row = RowPos;
    *MINRow = dataTable[Row] [0];
    for(Row = RowPos; Row<=1; Row++){
        for(Col = 0; Col < 5; Col++){
            if (*MINRow > dataTable[Row] [Col]) {
                *MINRow = dataTable[Row] [Col];
            }
        }
    }
}

/* Procedure meanValue */
void meanTableValue(Table dataTable, float *mean) {
    /* Kamus lokal */
    float SUM;

    SUM=0;
    for(Row = 0; Row<3; Row++){
        for(Col = 0; Col < 5; Col++){
            SUM = SUM + dataTable[Row] [Col];
        }
    }
    *mean = SUM/15;
}

/* Procedure getThingNames */
void getThingNames(Table dataTable, int RowPos) {
    switch (RowPos) {
      case 0: {
          puts("Barang tersebut adalah Roti");
          break;
      }
      case 1: {
          puts("Barang tersebut adalah Sabun");
          break;
      }
      case 2: {
          puts("Barang tersebut adalah Pena");
          break;
      }
    }
}

/* procedure getMonth */
void getMonth(Table dataTable, int ColPos) {
    switch (ColPos) {
      case 0: {
          puts("Terjual pada bulan Januari");
          break;
      }
      case 1: {
          puts("Terjual pada bulan Februari");
          break;
      }
      case 2: {
          puts("Terjual pada bulan Maret");
          break;
      }
      case 3: {
          puts("Terjual pada bulan April");
          break;
      }
      case 4: {
          puts("Terjual pada bulan Mei");
          break;
      }
    }
}

/* Procedure */
void menuHome() {
    puts("Menu pilihan : ");
    puts("1. Menampilkan data. ");
    puts("2. Mencari penjualan terbanyak. ");
    puts("3. Mencari penjualan terendah. ");
    puts("4. Mencari rata-rata penjualan.");
    puts("5. Menapilkan grafik. ");
    puts("6. Keluar...");
}
