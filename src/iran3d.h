/******************************************************************************
  Module Name : iran3d.h
  Module Date : 02/26/2014
  Module Auth : Yonggang Li based on iradina

  Description : Declares some general function of iran3d and some global variables.

  Others :
      Refers to iradina.
      Some switsches are defined which make iran3d safer but slower.

      Revision History:
      Date    Rel Ver.    Notes
      12/06/13            started designing;
      02/26/14            started coding;
      04/29/14            finished version_1.0.0;
******************************************************************************/
#ifndef IRAN3D_H
#define IRAN3D_H

/*------------------------------Includes-----------------------------*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "transport.h"
#include "fileio.h"
#include "material.h"
#include "utils.h"
#include "target.h"
#include "init.h"
#include "msh.h"

/* MPI=============================================== */
#include "mpimod.h"
/* MPI=============================================== */

/* or ------------------------------------*/
/* include some standard c libraries: */
//#include <string.h>
//#include <time.h>

/* include other modules: */
//#include "target.h"

/*------------------------------Defines------------------------------*/
/* Define some more options that need to be known during compilation.
   Switching these on makes iran3d slower but safer. */

#define SAFE_ROTATION        /* makes iran3d slower but SAFER */
#define SAFE_SQR_ROTATION    /* makes iran3d slower but SAFER */

//#define CHECK_NAN_VECTORS  /* makes iran3d not so slow as the par above */
                             /* but almost as safe against nan velocities */
#define RENORM_VELOCITIES    /* reduce vel unit vec to 1 */

/* if a recoil or ion hangs up, this ensure that it will be stopped after so
   many steps. This should be a large number if you simulate large structures. */
#define PROJ_HANGUP_SAFETY 100000000

/* modofied form iradina-V-"June 24th, 2013" */
#define VERSIONDATE "Apr. 29th, 2014"  /* first correct version */
#define VERSION 1
#define SUBVERSION 0
#define SUBSUBVERSION 0
#define RELEASESTRING ""
#define VERSIONCOMMENT " -- "

#define MAX_FILENAME_LENGTH 1024

/*--------------------------Global variables-------------------------*/
int print_level;               /* determines how much stuff is printed to the console
                                  0 means normal, positive values mean more, negative less */
int mem_usage_only;            /* if 1, then do not simulate anything, just estimate memory usage */
int mem_usage_details;         /* if 1, print more details for memory usage */
unsigned long int mem_usage;   /* if mem_usage active, then sum it up here (in bytes) */

char *ConfigFileName;          /* name of the general input config file */
char *TargetStructureFileName; /* filename of the file that define the structure of the target */
char *OutputFileBaseName;      /* all outputfiles begin with this name, so that's put them in a
                                  distinct directory if included in this name */
char *MaterialsFileName;       /* name of the file that defines the materials in the target */
char *ConversionFileName;      /* name of the converted input file (when converting from
                                  materials to elements) */
char *ElementsFileName;        /* name of the file that defines the elements in the target
                                  This is not needed for standard material based operation,
                                  but for conversion of one to another...
                                  so it is defined in both cases. */
char *TargetDensityMultFileName;  /* */

int wait_before_end;           /* if 1, the program only quits after pressing return key */
int output_format;             /* if 1, iradiana output format; if 2, cfg output_format */
int normalize_output;          /* if 1, the output of the program will be normalized to
                                  (1/cm^3)/(ions/cm^2) */
double unit_conversion_factor; /* This converts output to unit of (1/cm^3)per(1/cm^2) */
int    create_status_file;     /* if this is 1, then iran3d output its status regularly to
                                  a file that can be read by another program */
char *start_id_string;         /* string that helps other programs to identify iran3d output */
int   do_not_store_damage;     /* if 1, then far fewer data are stored to disc... saves memory */

/*-----------------------------Functions-----------------------------*/
int main (int argc, char *argv[]);  /* the main program */
int display_startup_message ();     /* does what you think it does */

#endif

