widthI = 2.44;
depthI = 2.44;

cornerW = 5.08/100;
cornerD = 5.08/100;
cornerH = 30.48/100;

translate([0,0,cornerH/2+1/100]){
   for (i=[0:3]){ 
        rotate([0,0,i*90]){
            translate([widthI/2-cornerW/2,depthI/2-cornerD/2,0]){
                cube([cornerW,cornerD,cornerH],true);
            }
        }
    }
}