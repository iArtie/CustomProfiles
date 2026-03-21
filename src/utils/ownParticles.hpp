#ifndef OWNPARTICLES_H
#define OWNPARTICLES_H

#include <Geode/Geode.hpp>

using namespace geode::prelude;

enum class SpecialEvent {
    None,
    Birthday,
    Christmas,
    NewYear
};

class ownParticles {
public:
    static SpecialEvent getCurrentEvent();

    static CCParticleSystemQuad* createBirthdayParticles(CCPoint position = { 160, 300 });
    static CCParticleSystemQuad* createChristmasParticles(CCPoint position = { 160, 300 });
    static CCParticleSystemQuad* createNewYearParticles(CCPoint position = { 160, 300 });

    static void startParticles(CCParticleSystemQuad* particles);
    static void stopParticles(CCParticleSystemQuad* particles);
    static void removeParticles(CCParticleSystemQuad* particles);
    static void addParticlesToLayer(CCLayer* layer, CCParticleSystemQuad* particles, int zOrder = 10);
    static void updateParticlesForEvent(CCLayer* layer);
};

#endif