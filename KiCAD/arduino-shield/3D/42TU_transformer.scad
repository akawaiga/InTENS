
// 42TU transformer

dy = .1675;
dx = .517;

cx = 0.72;
cy = 0.98;
cz = 0.74;

module trans() {
  // body
  color("grey")
    translate( [cx/3, 0, 0])
      cube( [cx/3, cy, cz]);
  color("#e0e0e0") {
      translate( [0, cy/5, cz/8])  cube( [cx, cy*3/5, 0.063]);
      translate( [0, cy/5, cz*6/8])  cube( [cx, cy*3/5, 0.063]);
  }
  color("#ffffe0") {
    translate( [cx/8, cy/5, cz/8])  cube( [cx*3/4, cy*3/5, cz*5/8]);
  }

  // wires
  translate( [0.1, 0.323, -.197]) {
    for( ix=[0:1]) {
      for( iy=[0:2]) {
	translate( [ix*dx, iy*dy, 0])
	  cylinder( d=.02, h=.3);
      }
    }
  }

  // tabs
  color("#e0e0e0") {
    translate( [cx/2-.05, 0, -0.2])
      cube( [.1, .03, .2]);
    translate( [cx/2-.05, cy-.03, -0.2])
      cube( [.1, .03, .2]);
  }
}

trans();
