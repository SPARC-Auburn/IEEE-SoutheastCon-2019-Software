$fn = 200;
module versa() {
    translate([0,0,66.1/2000+60.02/1000]){
    rotate([0,180,0]){
        cylinder(d=44.3/1000,h=66.1/1000,center=true,$fn=200);
        translate([0,0,60.02/2000+66.1/2000]){
            cube([44.45/1000,44.45/1000,60.02/1000],center=true);
            translate([0,0,40/2000+60.02/2000]){
                cylinder(r=0.0127/2,h=40/1000,$fn=6,center=true);
            }
        }
    }
    }
}
module wheel(){
    rotate([0,90,0]){
        cylinder(r=0.073025/2,h=0.01016,center=true);
    }
        //http://www.banebots.com/category/T40P-2875.html
}
module tube(sizeO, sizeI, l) {
    difference(){
        cube([sizeO,l,sizeO],center=true);
        cube([sizeI,l+0.1,sizeI],center=true);
    }
}
translate([0.2286/2-0.0254/2,0,0]){
    tube(0.0254,0.0254-0.003175,0.2286);
}
translate([-0.2286/2+0.0254/2,0,0]){
    tube(0.0254,0.0254-0.003175,0.2286);
}
translate([0,-0.2286/2+0.0254/2,0]){
    rotate([0,0,90]){
            tube(0.0254,0.0254-0.003175,0.2286-2*0.0254);
    }
}
*translate([0,0,0.5+0.2794-0.0254]){
    cube([1,1,1],center=true);
}
versa();
translate([0.254]){
wheel();
}