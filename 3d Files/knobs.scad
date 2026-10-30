$fn=60;  

module big_knob(radius,height,finger_r){
    difference(){
        union(){
        cylinder(r=radius,h=height);
        }

        //top chamfer
        translate([0,0,height+1.6])
        rotate_extrude()
        translate([radius,0])
        circle(r=4,$fn=4);

        //bottom chamfer
        rotate_extrude()
        translate([radius,0])
        circle(r=1.6,$fn=4);


        //knurling
        cuts=round(6.14*radius/3);
        echo("-----------------");
        echo(cuts);
        echo("-----------------");
        echo([0:cuts])
        for(i=[0:cuts])
            echo(i)
        rotate([0,0,i*360/cuts])
        linear_extrude(height=height+0.1,twist=120*(height/45))
        translate([radius,0])
        circle(r=0.8,$fn=4);

        //knurling
        for(i=[0:cuts])
        rotate([0,0,i*360/cuts])
        linear_extrude(height=height+0.1,twist=-120*(height/45))
        translate([radius,0])
        circle(r=0.8,$fn=4);
        translate([radius-finger_r-3,0,height-2])
        cylinder(r1=finger_r-1,r2=finger_r,h=3);
        translate([0,0,-0.01])
        difference(){
            cylinder(r=4.76,h=height-2);
            translate([-4.76,4.76/2,0])cube([4.76*2,4.76*2,height-2]);
        }

    }
}

big_knob(35,15,10);