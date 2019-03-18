//units are in meters cause gazebo
spacetelDia = 7.6962/100;
spacetelHeight = 4.572/100;
spacetelPlacementRadius = 1;

$fn = 1000;
translate([0,0,spacetelHeight/2]){ //spacetels
    for (i=[0:3]){ 
        rotate([0,0,i*90]){
            translate([spacetelPlacementRadius,0,0]){
                cylinder(spacetelHeight,d1 = spacetelDia, d2 = spacetelDia,center = true);
            }
        }
    }
}