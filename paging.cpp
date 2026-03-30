#include <stdio.h>

struct pstruct
{
    int fno;
    int pbit;
} ptable[10];

int pmsize, lmsize, psize, frame, page, ftable[20], frameno;

void info()
{
    printf("\n\nMEMORY MANAGEMENT USING PAGING\n\n");
    printf("\n\nEnter the Size of Physical memory: ");
    scanf("%d", &pmsize);
    printf("\n\nEnter the size of Logical memory: ");
    scanf("%d", &lmsize);
    printf("\n\nEnter the partition size: ");
    scanf("%d", &psize);

    frame = pmsize / psize;
    page = lmsize / psize;

    printf("\nThe physical memory is divided into %d frames\n", frame);
    printf("\nThe logical memory is divided into %d pages\n", page);
}

void assign()
{
    int i;

    for (i = 0; i < page; i++)
    {
        ptable[i].fno = -1;
        ptable[i].pbit = -1;
    }

    for (i = 0; i < frame; i++)
        ftable[i] = -1;

    for (i = 0; i < page; i++)
    {
        printf("\nEnter the frame number for page %d: ", i);
        scanf("%d", &frameno);

        ftable[frameno] = i;
        ptable[i].fno = frameno;
        ptable[i].pbit = 1;
    }

    printf("\n\nPAGE TABLE\n");
    printf("Page\tFrame\tPresence\n");

    for (i = 0; i < page; i++)
        printf("%d\t%d\t%d\n", i, ptable[i].fno, ptable[i].pbit);

    printf("\nFRAME TABLE\n");
    printf("Frame\tPage\n");

    for (i = 0; i < frame; i++)
        printf("%d\t%d\n", i, ftable[i]);
}

void cphyaddr()
{
    int laddr, paddr, disp, phyaddr, baddr;

    printf("\n\n       7       2\n");
    printf("Process to create the Physical Address\n");

    printf("Enter the Base Address: ");
    scanf("%d", &baddr);

    printf("Enter the Logical Address: ");
    scanf("%d", &laddr);

    paddr = laddr / psize;
    disp = laddr % psize;

    if (ptable[paddr].pbit == 1)
        phyaddr = baddr + (ptable[paddr].fno * psize) + disp;
    else
    {
        printf("Page not present in physical memory.\n");
        return;
    }

    printf("The Physical Address where the instruction present: %d\n", phyaddr);
}

int main()
{
    info();
    assign();
    cphyaddr();
    return 0;
}

