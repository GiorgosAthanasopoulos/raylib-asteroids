typedef struct {
  // TODO: create necessary fields for bullet entity
} Bullet;

Bullet *BulletInit() {
  // TODO: implement Bullet::Init
}

void BulletDeinit() {
  // TODO: implement Bullet::deinit
}

void BulletUpdate() {
  // TODO: implement Bullet::update
  // TODO: check coliisions with border/objects
}

void BulletUpdateAfterResize() {
  // TODO: implement Bullet::updateafterresize
  // TODO: update x, y with same rations before screen resize
}

void BulletDraw() {
  // TODO: implement Bullet::draw
  // TOOD: Maybe add custom sprite?
}
