/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])//Gets information over the comand line 
{
    // ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];//This is the pointer for the file that i get and its called'infile'
    char *outfile = argv[2];//The pointer out its call "outfile"
    
    // so the pointers up here are == to the file they point to the files  


//////////  opening files into pointers ///////////////////

    // open input file                                                            infile == to the file introduced
    FILE *inptr = fopen(infile, "r");//calls the pointer "inptr", the file is calls the pointer "infile" in read mode 
    
    ////////// making sure that everithing goes well
    if (inptr == NULL)//If that file is doesn't exist does this
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file// oufile poiter that will be writed outfile == name written in the comand line
    FILE *outptr = fopen(outfile, "w");//Opens a poiter call outptr to write in a file to call outfile in write mode
    
    ////////// making sure that everithing goes well
    if (outptr == NULL)//if the pointer "outptr" is null meaning that there's not enought memory or something else
    {
        fclose(inptr);//Close the file "inptr"
        fprintf(stderr, "Could not create %s.\n", outfile);//Calls stderr and it writes that into outfile
        return 3;// Returns 3 
    }

/////////////     Buffer     //////////////////////////////

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;//creates "bf" a type of struck called "BIT MAP FILE HEADER" that comes in bmp.h
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);//the buffer will be "bf", size, 1, from the input(file in)
                                    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;// creates a second struc call "bi" that constaint the BIT MAP INFO HEADER  
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
///////////////////////////////////////////////////////////   

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)//if anything of this is diferent of this data then
    {
        fclose(outptr);//close outptr
        fclose(inptr);//close inptr
        fprintf(stderr, "Unsupported file format.\n");//print out 
        return 4;
    }
    
    /////////////////////////////
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);//call the funtion to fwrite
    //call the struck bf, size , quantity, write over outptr
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);



    // determine padding for scanlines
    //( 4 - (struck bi biwidth value * size of rgb triple) mod 4 ) mod 4
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;///ecuation to make sure that the padding its well done
    //padding holds a value

    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)///get the absolute value of biheight and iterates over it
    {       // interates over height
    
    
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)//this one iterates over the width
        {
            // temporary storage
            RGBTRIPLE triple;//declares this vareable

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            //poits to triple, size , 1 , from the input
            
            
            // Switching red to  white  
            //   0   0 255  red
            if ( triple.rgbtBlue == 0x00 ||triple.rgbtGreen == 0x00  ||triple.rgbtRed == 0xff  )
            {
                triple.rgbtBlue = 0xff ;
                triple.rgbtGreen = 0xff ;
                triple.rgbtRed = 0xff ;
            }
            
            ///Switching white to blue
            // 255 255 255  white
            else if ( triple.rgbtBlue == 0xff ||triple.rgbtGreen == 0xff ||triple.rgbtRed == 0xff  )
            {
                triple.rgbtBlue = 0xff;
                triple.rgbtGreen = 0x00;
                triple.rgbtRed = 0x00;
            }
            
            //printf(" %3i %3i %3i|", triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            //writes from triple, size, 1 , to output
            
        }

        //fishes the image (bi.biWidth) but still in the same line so...
        //here posisionates the writer in the input file(readind) to the current line
        
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);// uses seek positionate the writer just after the padding  
        // poiter input, numero de padding, from current position
        
        
        ////so now that i am at the end of the image i keep wrinting

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);//puts in outpointer "0x00" the number of times recured for the pading
        }
    }
    
    /////   Closes everything ////////
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
