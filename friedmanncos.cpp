
#include <iostream>
#include <fstream>
#include <cmath>

// Calcule da/dt à partir de l’équation de Friedmann (univers FLRW)
double scaleFactorDerivative(double scaleFactor,
                             double hubbleConst,
                             double omegaMatter,
                             double omegaRadiation,
                             double omegaLambda,
                             double omegaCurvature)
{
    double friedmannTerm =
          omegaMatter    / std::pow(scaleFactor, 3)   // matière
        + omegaRadiation / std::pow(scaleFactor, 4)   // rayonnement
        + omegaLambda                                // énergie du vide
        + omegaCurvature / std::pow(scaleFactor, 2); // courbure

    return hubbleConst * scaleFactor * std::sqrt(friedmannTerm);
}

int main()
{
    // Fichier de sortie : temps et facteur d’échelle
    std::ofstream output("scale_factor.dat");

    if (!output) return 1;

    // Paramètres cosmologiques (univers matière)
    double hubbleConst     = 1.0;
    double omegaMatter     = 1.0;
    double omegaRadiation  = 0.0;
    double omegaLambda     = 0.0;
    double omegaCurvature  = 0.0;

    // Conditions initiales
    double scaleFactor = 1e-3;   // a(t) initial
    double time        = 0.0;    // temps initial
    double timeStep    = 1e-3;   // pas de temps

    // Intégration temporelle (Euler explicite)
    for (int step = 0; step < 10000; step++)
    {
        output << time << " " << scaleFactor << "\n";

        scaleFactor += timeStep *
            scaleFactorDerivative(scaleFactor,
                                  hubbleConst,
                                  omegaMatter,
                                  omegaRadiation,
                                  omegaLambda,
                                  omegaCurvature);

        time += timeStep;
    }

    output.close();
    return 0;
}
