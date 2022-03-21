#include <iostream>
#include <igl/readMSH.h>
#include <polyscope/volume_mesh.h>
void main()
{
	Eigen::MatrixXd V;
	Eigen::MatrixXi T, F;
	Eigen::VectorXi tritag, tettag;
	igl::readMSH("../data/woola.msh", V, F, T, tritag, tettag);

	polyscope::init();
	polyscope::registerVolumeMesh("Woola", V, T);

	std::cout << "Hello Polyscope!" << std::endl;
	polyscope::show();
}
