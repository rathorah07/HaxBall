#include "Collisions.h"
#include "Player.h"
#include "Ball.h"
#include "Interaction.h"
#include "Vector.h"
#include <iostream>
#include <cstdlib>
#include "Constants.h"
using namespace std;


void collision(player & rider, ball & freedom){
	if(!rider.hit){
	Vector unit_x(1.0, 0.0);
	Vector unit_y(0.0, 1.0);
	Vector normal(rider.pos[0] - freedom.pos[0], rider.pos[1] - freedom.pos[1]);
	Vector normal2(freedom.pos[0] - rider.pos[0], freedom.pos[1] - rider.pos[1]);
	
    float mass1 = 1.0;
	float mass2 = 1.0;
	
	Vector unit_normal = normal.unit_vector(); /**<unit vector along the normal of the collison*/
	Vector unit_normal2 = normal2.unit_vector();

	Vector unit_tangent(-1.0 * (unit_normal._vector[1]), unit_normal._vector[0]); /**<unit vector along the tangent at the point of collison */

	// velocity vectors of the balls
	Vector v1(freedom.vel[0], freedom.vel[1]); /**<velocity vector of circle1 */
	Vector v2(rider.vel[0], rider.vel[1]); /**<velocity vector of cirlce2 */
	
	// dividing the velocity vectors into the rectangular normal and the tangential directions
	float v1t = v1.scalar_product(unit_tangent); /**<tangential component of velocity of circle1 */
	float v1n = v1.scalar_product(unit_normal); /**<normal component of velocity of cirlce1 */
	float v2t = v2.scalar_product(unit_tangent); /**<tangential component of velocity of circle2 */
	float v2n = v2.scalar_product(unit_normal); /**<normal component of velocity of circle2 */
	
	float approach = v2n - v1n;
	//cout<<check_contact(rider, freedom)<<endl;
	
	if (check_contact(rider, freedom)){
		
		rider.in_contact = true;	//check these conditions later might cause problem
		freedom.in_contact = true;	
		if (approach > 0){
			return ;
		}
	
	
	float v1n_ = (v1n * (mass1 - mass2) + 2 * mass2 * v2n) / (mass1 + mass2);
	float v2n_ = (v2n * (mass2 - mass1) + 2 * mass1 * v1n) / (mass1 + mass2);

	Vector temp = unit_normal.scalar_multiplication(v1n_);
	Vector v1f = (unit_tangent.scalar_multiplication(v1t)).addition(temp);

	temp = unit_normal.scalar_multiplication(v2n_);
	Vector v2f = (unit_tangent.scalar_multiplication(v2t)).addition(temp);
	
    freedom.vel[0] = v1f._vector[0];
    freedom.vel[1] = v1f._vector[1];

    rider.vel[0] = v2f._vector[0];   // mine
    rider.vel[1] = v2f._vector[1];

    //rider.assign_direction(v2f.unit_vector());
	}

	else{
		rider.in_contact = false;
		freedom.in_contact = false;
	}
	}

	else{
        	rider.in_contact= true;	//check these conditions later might cause problem
           freedom.in_contact = true;
	Vector unit_x(1.0, 0.0);
	Vector unit_y(0.0, 1.0);
	
	Vector normal(rider.pos[0] - freedom.pos[0], rider.pos[1] - freedom.pos[1]);
	
    float mass1 = 4.0;
	float mass2 = 2.0;
	
	Vector unit_normal = normal.unit_vector();

	Vector unit_tangent(-1.0 * (unit_normal._vector[1]), unit_normal._vector[0]);

	rider.inten[0] = rider.intensity*(rider.direction.scalar_product(unit_x));
	rider.inten[1] = rider.intensity*(rider.direction.scalar_product(unit_y));
	Vector v1(freedom.vel[0], freedom.vel[1]);
	Vector v2(rider.inten[0], rider.inten[1]);
	
	float v1t = v1.scalar_product(unit_tangent);
	float v1n = v1.scalar_product(unit_normal);
	float v2t = v2.scalar_product(unit_tangent);
	float v2n = v2.scalar_product(unit_normal);
	

    /*float approach = v2n - v1n;
				
    if (approach > 0){
		return ;
    } */

	
	float v1n_ = (v1n * (mass1 - mass2) + 2 * mass2 * v2n) / (mass1 + mass2);
	float v2n_ = (v2n * (mass2 - mass1) + 2 * mass1 * v1n) / (mass1 + mass2);

	Vector temp = unit_normal.scalar_multiplication(v1n_);
	Vector v1f = (unit_tangent.scalar_multiplication(v1t)).addition(temp);
	
	temp = unit_normal.scalar_multiplication(v2n_);
	Vector v2f = (unit_tangent.scalar_multiplication(v2t)).addition(temp);

    //freedom.vel[0] = rider.intensity;
    // freedom.vel[1] = rider.intensity;
    freedom.vel[0] = v1f._vector[0];
    freedom.vel[1] = v1f._vector[1];
    /*rider.vel[0] = v2f._vector[0];
    rider.vel[1] = v2f._vector[1]; */
    rider.stop_player();
    //rider.assign_direction(v2f.unit_vector());

	}
}

void check_post(ball & freedom){
	if (check_contact_LT(freedom)){
		collision_wall(freedom, leftp, (top/_ratio));
		//cout << "collision" << endl;
		//exit(0);
	}

	else if (check_contact_RT(freedom)){
		collision_wall(freedom, rightp, (top/_ratio));
		//cout << "collision" << endl;
		//exit(0);
	}

	else if (check_contact_LB(freedom)){
		collision_wall(freedom, leftp, -(top/_ratio));
		//cout << "collision" << endl;
		//exit(0);	
	}

	else if (check_contact_RB(freedom)){
		collision_wall(freedom, rightp, -(top/_ratio));
		//cout << "collision" << endl;
		//exit(0);
	}

	else{
		//cout << "collision nahin hua!!!!" << endl;
	}
}

void collision_wall(ball & freedom, float x, float y){
	Vector initial(freedom.vel[0], freedom.vel[1]);
	Vector normal(freedom.pos[0] - x, freedom.pos[1] - y);
	Vector normal2(x - freedom.pos[0], y - freedom.pos[1]);

	Vector unit_normal = normal.unit_vector();
	Vector unit_normal2 = normal2.unit_vector();

	Vector unit_tangent(-1.0 * (unit_normal._vector[1]), unit_normal._vector[0]);

	Vector along_tangent = unit_tangent.scalar_multiplication(initial.scalar_product(unit_tangent));
	Vector along_normal = unit_normal.scalar_multiplication(initial.scalar_product(unit_normal2));

	Vector final = along_tangent.addition(along_normal);

	freedom.vel[0] = final._vector[0];
	freedom.vel[1] = final._vector[1];
}

void collision_players(player & rider, player & enemy){
	Vector unit_x(1.0, 0.0);
	Vector unit_y(0.0, 1.0);
	Vector normal(rider.pos[0] - enemy.pos[0], rider.pos[1] - enemy.pos[1]);
	//Vector normal2(freedom.pos[0] - rider.pos[0], freedom.pos[1] - rider.pos[1]);
	
	float mass1 = 1.0;
	float mass2 = 1.0;
			
	Vector unit_normal = normal.unit_vector(); /**<unit vector along the normal of the collison*/
	//Vector unit_normal2 = normal2.unit_vector();

	Vector unit_tangent(-1.0 * (unit_normal._vector[1]), unit_normal._vector[0]); /**<unit vector along the tangent at the point of collison */

	// velocity vectors of the balls
	Vector v1(enemy.vel[0], enemy.vel[1]); /**<velocity vector of circle1 */
	Vector v2(rider.vel[0], rider.vel[1]); /**<velocity vector of cirlce2 */
	
	// dividing the velocity vectors into the rectangular normal and the tangential directions
	float v1t = v1.scalar_product(unit_tangent); /**<tangential component of velocity of circle1 */
	float v1n = v1.scalar_product(unit_normal); /**<normal component of velocity of cirlce1 */
	float v2t = v2.scalar_product(unit_tangent); /**<tangential component of velocity of circle2 */
	float v2n = v2.scalar_product(unit_normal); /**<normal component of velocity of circle2 */
	
	float approach = v2n - v1n;
	//cout<<check_contact(rider, freedom)<<endl;
	
	if (check_contact_player(rider, enemy)){
			
		if (approach > 0){
			return ;
		}
	
	
	float v1n_ = (v1n * (mass1 - mass2) + 2 * mass2 * v2n) / (mass1 + mass2);
	float v2n_ = (v2n * (mass2 - mass1) + 2 * mass1 * v1n) / (mass1 + mass2);

	Vector temp = unit_normal.scalar_multiplication(v1n_);
	Vector v1f = (unit_tangent.scalar_multiplication(v1t)).addition(temp);

	temp = unit_normal.scalar_multiplication(v2n_);
	Vector v2f = (unit_tangent.scalar_multiplication(v2t)).addition(temp);
	
	enemy.vel[0] = v1f._vector[0];
	enemy.vel[1] = v1f._vector[1];
	rider.vel[0] = v2f._vector[0];
	rider.vel[1] = v2f._vector[1];
}
}
