#ifndef _DISASSEMBLER
#define _DISASSEMBLER

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "./TAM/Machine.h"
#include "./TAM/Instruction.h"

using namespace std;

class Disassembler {


public:

  string objectName;
  Machine* mach;
  int CT;

  void writeR (char leftbracket, int r, char rightbracket);
  void blankN();
  void writeN (int n);
  void writeD (int d);
  void writePrimitive (int d);
  void writeInstruction (Instruction* instr);
  void disassembleProgram();
  void loadObjectProgram (string objectName);
  Disassembler();

};


  Disassembler::Disassembler(){
  
  mach = new Machine();
  
  
  
  
  
  }


  void Disassembler::writeR (char leftbracket, int r, char rightbracket) {

    printf("%c",leftbracket);

    
     if(r == mach->CBr){
        printf("CB");
        }
      else if(r == mach->CTr){
		printf("CT");
		}
      else if(r == mach->PBr){
		printf("PB");
		}
      else if(r == mach->PTr){
		printf("PT");
		}
      else if(r == mach->SBr){
		printf("SB");
		}
      else if(r == mach->STr){
		printf("ST");
		}
      else if(r == mach->HBr){
		printf("HB");
		}
      else if(r == mach->HTr){
		printf("HT");
		}
      else if(r == mach->LBr){
		printf("LB");
		}
      else if(r == mach->L1r){
		printf("L1");
		}
      else if(r == mach->L2r){
		printf("L2");
		}
      else if(r == mach->L3r){
		printf("L3");
		}
      else if(r == mach->L4r){
		printf("L4");
		}
      else if(r == mach->L5r){
		printf("L5");
		}
      else if(r == mach->L6r){
		printf("L6");
		}
      else if(r == mach->CPr){
		printf("CP");
		}
    
    printf("%c",rightbracket);
  }



  /**
   * Writes a void n-field of an instruction.
   */

  void Disassembler::blankN() {
    printf("      ");
  }

  // Writes the n-field of an instruction.
  /**
   * Writes the n-field of an instruction in the form "(n)".
   * @param n	the integer to write.
   */
  void Disassembler::writeN (int n) {
    printf("(%d) ",n);

    if (n < 10)
      printf("  ");
    else if (n < 100)
      printf(" ");
  }

  /**
   * Writes the d-field of an instruction.
   * @param d	the integer to write.
   */
  void Disassembler::writeD (int d) {
    printf("%d",d);
  }

  /**
   * Writes the name of primitive routine with relative address d.
   * @param d	the displacment of the primitive routine.
   */
  void Disassembler::writePrimitive (int d) {
    
    if(d == mach->idDisplacement){
        printf("id      ");
		}
    else if(d == mach->notDisplacement){
		printf("not     ");
		}
      else if(d == mach->andDisplacement){
		printf("and     ");
		}
      else if(d == mach->orDisplacement){
		printf("or      ");
		}
      else if(d == mach->succDisplacement){
		printf("succ    ");
		}
      else if(d == mach->predDisplacement){
		printf("pred    ");
		}
      else if(d == mach->negDisplacement){
		printf("neg     ");
		}
      else if(d == mach->addDisplacement){
		printf("add     ");
		}
      else if(d == mach->subDisplacement){
		printf("sub     ");
		}
      else if(d == mach->multDisplacement){
		printf("mult    ");
		}
      else if(d == mach->divDisplacement){
		printf("div     ");
		}
      else if(d == mach->modDisplacement){
		printf("mod     ");
		}
      else if(d == mach->ltDisplacement){
		printf("lt      ");
		}
      else if(d == mach->leDisplacement){
		printf("le      ");
		}
      else if(d == mach->geDisplacement){
		printf("ge      ");
		}
      else if(d == mach->gtDisplacement){
		printf("gt      ");
		}
      else if(d == mach->eqDisplacement){
		printf("eq      ");
		}
      else if(d == mach->neDisplacement){
		printf("ne      ");
		}
      else if(d == mach->eolDisplacement){
		printf("eol     ");
		}
      else if(d == mach->eofDisplacement){
		printf("eof     ");
		}
      else if(d == mach->getDisplacement){
		printf("get     ");
		}
      else if(d == mach->putDisplacement){
		printf("put     ");
		}
      else if(d == mach->geteolDisplacement){
		printf("geteol  ");
		}
      else if(d == mach->puteolDisplacement){
		printf("puteol  ");
		}
      else if(d == mach->getintDisplacement){
		printf("getint  ");
		}
      else if(d == mach->putintDisplacement){
		printf("putint  ");
		}
      else if(d == mach->newDisplacement){
		printf("new     ");
		}
      else if(d == mach->disposeDisplacement){
		printf("dispose ");
		}
  }

  /**
   * Writes the given instruction in assembly-code format.
   * @param instr	the instruction to display.
   */
  void Disassembler::writeInstruction (Instruction* instr) {

     if(instr->op == mach->LOADop){
		printf("LOAD  ");
		writeN(instr->n);
		writeD(instr->d);
		writeR('[', instr->r, ']');
		}

      else if(instr->op == mach->LOADAop){
        printf("LOADA ");
        blankN();
        writeD(instr->d);
        writeR('[', instr->r, ']');
        }

      else if(instr->op == mach->LOADIop){
        printf("LOADI ");
        writeN(instr->n);
        }

      else if(instr->op == mach->LOADLop){
        printf("LOADL ");
        blankN();
        writeD(instr->d);
        }

      else if(instr->op == mach->STOREop){
        printf("STORE ");
        writeN(instr->n);
        writeD(instr->d);
        writeR('[', instr->r, ']');
        }

      else if(instr->op == mach->STOREIop){
        printf("STOREI");
        writeN(instr->n);
        }

      else if(instr->op == mach->CALLop){
        printf("CALL  ");
        if (instr->r == mach->PBr) {
          blankN();
          writePrimitive(instr->d);
        } else {
          writeR('(', instr->n, ')');
          printf("  ");
          writeD(instr->d);
          writeR('[', instr->r, ']');
        }
        }

      else if(instr->op == mach->CALLIop){
        printf("CALLI ");
	}

      else if(instr->op == mach->RETURNop){
        printf("RETURN");
        writeN(instr->n);
        writeD(instr->d);
        }

      else if(instr->op == mach->PUSHop){
        printf("PUSH  ");
        blankN();
        writeD(instr->d);
        }

      else if(instr->op == mach->POPop){
        printf("POP   ");
        writeN(instr->n);
        writeD(instr->d);
        }

      else if(instr->op == mach->JUMPop){
        printf("JUMP  ");
        blankN();
        writeD(instr->d);
        writeR('[', instr->r, ']');
        }

      else if(instr->op == mach->JUMPIop){
        printf("JUMPI ");
        }

      else if(instr->op == mach->JUMPIFop){
        printf("JUMPIF");
        writeN(instr->n);
        writeD(instr->d);
        writeR('[', instr->r, ']');
        }

      else if(instr->op == mach->HALTop){
        printf("HALT  ");
		 }
  }

  /**
   * Writes all instructions of the program in code store.
   */
  void Disassembler::disassembleProgram() {
    for (int addr = mach->CB; addr < CT; addr++) {
      printf ("%d:  ",addr);
      writeInstruction(mach->code[addr]);
      printf("\n");
    }
  }


// LOADING

  /**
   * Loads the TAM object program into code store from the named file.
   * @param objectName	the name of the file containing the program.
   */
  void Disassembler::loadObjectProgram (string objectName) {

   std::ifstream objectStream(objectName.c_str(),ios_base::binary);

    int addr;
    bool finished = false;


	Instruction* temp_instr = new Instruction();


      addr = mach->CB;
      while (!finished) {
        mach->code[addr] = temp_instr->read(objectStream);
		if (mach->code[addr] == NULL){
          finished = true;
		  addr = addr - 1;}
        else
          addr = addr + 1;
      }

      CT = addr;
    
  }



#endif