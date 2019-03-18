
centerW = .23;
centerD = .23;
centerH = .30;

translate([0,0,centerH/2 +1/100]){//center tower
    rotate([0,0,45]){ 
        cube([centerW,centerD,centerH],true);
    }
}
