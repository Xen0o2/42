-- AlterTable
ALTER TABLE "User" ADD COLUMN     "defeat" INTEGER NOT NULL DEFAULT 0,
ADD COLUMN     "experience" DOUBLE PRECISION NOT NULL DEFAULT 0,
ADD COLUMN     "level" INTEGER NOT NULL DEFAULT 1,
ADD COLUMN     "victory" INTEGER NOT NULL DEFAULT 0;