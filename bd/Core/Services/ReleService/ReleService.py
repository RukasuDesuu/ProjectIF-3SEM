from typing import List
from ..BaseService import BaseService
from bd.Models.Models import ReleCod

class ReleService(BaseService):
    def __init__(self) -> None:
        super().__init__(ReleCod)

    def GetReleByMinMax(self, ifrt:float)->List[ReleCod]:
        query = self._session.query(ReleCod).filter(ReleCod.imin <= ifrt, ReleCod.imax >= ifrt)
        return query.all()