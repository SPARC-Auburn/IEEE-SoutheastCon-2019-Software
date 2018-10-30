$fn=200;
module tube(sizeO, sizeI, l) {
    difference(){
        cube([sizeO*0.999,l,sizeO*0.999],center=true);
        cube([sizeI,l+0.1,sizeI],center=true);
    }
}
module wheel(){
    rotate([0,90,0]){
        cylinder(r=2.875*2.54/200,h=0.4*2.54/100,center=true);
    }
}
module u(){
    translate([(0.2286/2-0.0254/4),0,0]){
        tube(0.0254/2,0.0254/2-0.003175,0.2286);
    }
    translate([-(0.2286/2-0.0254/4),0,0]){
        tube(0.0254/2,0.0254/2-0.003175,0.2286);
    }
    translate([0,-0.2286/2+0.0254/4,0]){
        rotate([0,0,90]){
                tube(0.0254/2,0.0254/2-0.003175,0.2286-0.0254);
        }
    }
    translate([0.2286/2-0.0254/2-0.6*2.54/200,0.2286/2-0.0254/4,0]){
        rotate([0,0,90]){
            tube(0.0254/2,0.0254/2-0.003175,0.6*2.54/100);
        }
    }
    translate([-(0.2286/2-0.0254/2-0.6*2.54/200),0.2286/2-0.0254/4,0]){
        rotate([0,0,90]){
            tube(0.0254/2,0.0254/2-0.003175,0.6*2.54/100);
        }
    }
    translate([-(0.2286/2-0.0254*3/4-0.6*2.54/100),0.0254/4,0]){
        tube(0.0254/2,0.0254/2-0.003175,0.2286-0.0254/2);
    }
    translate([(0.2286/2-0.0254*3/4-0.6*2.54/100),0.0254/4,0]){
        tube(0.0254/2,0.0254/2-0.003175,0.2286-0.0254/2);
    }
}
for (i=[0:5]){
    translate([0,0,i*0.0254/2]){
            u();
    }
}
*translate([0,0,2.875*2.54/200*5/8]){
    translate([-0.2286/2+0.0254/2+0.6*2.54/200,0.2286/2-2.875*2.54/200-0.0254/2-0.2*2.54/100,0]){
        wheel();
    }
    translate([-0.2286/2+0.0254/2+0.6*2.54/200,-(0.2286/2-2.875*2.54/200-0.0254/2-0.2*2.54/100),0]){
        wheel();
    }
    translate([0.2286/2-0.0254/2-0.6*2.54/200,0.2286/2-2.875*2.54/200-0.0254/2-0.2*2.54/100,0]){
        wheel();
    }
    translate([0.2286/2-0.0254/2-0.6*2.54/200,-(0.2286/2-2.875*2.54/200-0.0254/2-0.2*2.54/100),0]){
        wheel();
    }
}
