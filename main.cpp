#include <iostream>
#include <igl/readMSH.h>
#include <polyscope/volume_mesh.h>
#include <igl/get_seconds.h>
Eigen::MatrixXd V;
Eigen::MatrixXi T;
polyscope::VolumeMesh* mesh;
// Your callback functions
void myCallback() {

	
	if (mesh)
	{
		Eigen::RowVector3d disp = Eigen::RowVector3d(0.1, 0.1, 0);
		V.rowwise() += disp;
	    double t_start = igl::get_seconds();
		mesh->updateVertexPositions(V);
		printf("Re-Initializing  : %g seconds \n", t_start - igl::get_seconds());
		t_start = igl::get_seconds();
		mesh->updateVertexPositions(V, true);		//pass update frame buffer so we do a few things: pass the data buffer directly to glSubBufferData (avoiding preprocessing loop) and we call glSubBufferData
		printf("Updating : %g seconds \n", t_start - igl::get_seconds());
	}
}


void main()
{
	polyscope::init();

	Eigen::MatrixXi F;
	Eigen::VectorXi tritag, tettag;
	igl::readMSH("../data/woola.msh", V, F, T, tritag, tettag);

	
    mesh = polyscope::registerTetMesh("Woola", V, T);

	std::cout << "Hello Polyscope!" << std::endl;

	polyscope::state::userCallback = myCallback;
	polyscope::show();
}
