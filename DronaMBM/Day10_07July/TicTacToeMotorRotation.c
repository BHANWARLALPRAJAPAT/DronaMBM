#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define BEAM_LEN 65 // Denotes the Length of Links
#define GAP 24      // denote the gap between Holes
double rad_to_degree(double rad)
{
    return rad * (180 / PI);
}
double getRotationAngle(int psX, int psY)
{
    double rotationAngle = 90.0;
    if (psX == 0)
        return rotationAngle;
    rotationAngle = rad_to_degree(atan((float)psY / psX));
    if (psX < 0)
        rotationAngle += 180;
    return rotationAngle;
}
double min(double a, double b)
{
    if (a > b)
        return b;
    return a;
}
double max(double a, double b)
{
    if (a < b)
        return b;
    return a;
}
int main()
{
    float BoardAngle[5][5][2], RackAngle[2][6][2];
    int psX, psY;
    float minAlpha = 360, minBeta = 360, maxAlpha = -360, maxBeta = -360;
    double beta, alphaPrime, alpha, rotationAngle;
    // printf("For Rack\n");
    for (int i = 0; i < 2; i++)
    {
        psY = GAP * (4 - i);
        for (int j = 0; j < 6; j++)
        {
            psX = GAP * (j - 2);

            rotationAngle = getRotationAngle(psX, psY);
            alphaPrime = rad_to_degree(acos(sqrt(psX * psX + psY * psY) / (2 * BEAM_LEN)));
            beta = 180 - 2 * alphaPrime;
            alpha = alphaPrime + rotationAngle;

            RackAngle[i][j][0] = alpha;
            RackAngle[i][j][1] = beta;

            minAlpha = min(minAlpha, alpha);
            minBeta = min(minBeta, beta);
            maxAlpha = max(maxAlpha, alpha);
            maxBeta = max(maxBeta, beta);

            printf("[ %6.2f %6.2f ]", alpha, beta);
        }
        printf("\n");
    }
    // printf("For Board\n");
    for (int i = 0; i < 5; i++)
    {
        psY = GAP * (2 - i);

        for (int j = 0; j < 3; j++)
            printf("[               ]");

        for (int j = 0; j < 5; j++)
        {

            psX = GAP * (j + 1);

            rotationAngle = getRotationAngle(psX, psY);
            alphaPrime = rad_to_degree(acos(sqrt(psX * psX + psY * psY) / (2 * BEAM_LEN)));
            alpha = alphaPrime + rotationAngle;
            beta = 180 - 2 * alphaPrime;

            BoardAngle[i][j][0] = alpha;
            BoardAngle[i][j][1] = beta;

            minAlpha = min(minAlpha, alpha);
            minBeta = min(minBeta, beta);
            maxAlpha = max(maxAlpha, alpha);
            maxBeta = max(maxBeta, beta);

            printf("[ %6.2f %6.2f ]", alpha, beta);
        }
        printf("\n");
    }
    printf("[ %6.2f %6.2f ] [ %6.2f %6.2f ]", minAlpha, maxAlpha, minBeta, maxBeta);
    return 0;
}
// Output:
// [150.91 111.30][144.47  99.14][132.40  95.20][116.39  99.14][ 97.78 111.30][ 75.75 134.76]
// [171.96  83.46][162.72  71.44][146.37  67.26][125.85  71.44][104.58  83.46][ 83.44 103.12]
// [             ][             ][             ][129.05  48.76][103.52  62.96][ 81.96  83.46][ 60.91 111.30][ 27.98 167.64]
// [             ][             ][             ][119.87  30.27][ 92.18  48.76][ 72.72  71.44][ 54.47  99.14][ 31.03 140.56]
// [             ][             ][             ][ 79.36  21.28][ 68.33  43.34][ 56.37  67.26][ 42.40  95.20][ 22.62 134.76]
// [             ][             ][             ][ 29.87  30.27][ 39.05  48.76][ 35.85  71.44][ 26.39  99.14][  8.41 140.56]
// [             ][             ][             ][  2.18  48.76][ 13.52  62.96][ 14.58  83.46][  7.78 111.30][-15.62 167.64]