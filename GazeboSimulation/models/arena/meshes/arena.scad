// all dimensions are meters cause gazebo
widthO = 2.74;
depthO = 2.74;
widthI = 2.44;
depthI = 2.44;
height = .30;





$fn = 2000; 
translate([0,0,height/2+0.5/100]){ // translate so the zero axis of the model is the bottom of the plane
    difference(){//main arena
        cube([widthO,depthO,height+1/100],true);
        translate([0,0,1/100]){
            cube([widthI,depthI,height],true);
        }
    }
}


