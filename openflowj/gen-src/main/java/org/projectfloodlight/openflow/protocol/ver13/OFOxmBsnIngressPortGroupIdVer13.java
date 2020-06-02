// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmBsnIngressPortGroupIdVer13 implements OFOxmBsnIngressPortGroupId {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmBsnIngressPortGroupIdVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 8;

        private final static ClassId DEFAULT_VALUE = ClassId.NONE;

    // OF message fields
    private final ClassId value;
//
    // Immutable default instance
    final static OFOxmBsnIngressPortGroupIdVer13 DEFAULT = new OFOxmBsnIngressPortGroupIdVer13(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmBsnIngressPortGroupIdVer13(ClassId value) {
        if(value == null) {
            throw new NullPointerException("OFOxmBsnIngressPortGroupIdVer13: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x32804L;
    }

    @Override
    public ClassId getValue() {
        return value;
    }

    public OFOxm<ClassId> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public ClassId getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<ClassId> getMatchField() {
        return MatchField.BSN_INGRESS_PORT_GROUP_ID;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFOxmBsnIngressPortGroupId.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmBsnIngressPortGroupId.Builder {
        final OFOxmBsnIngressPortGroupIdVer13 parentMessage;

        // OF message fields
        private boolean valueSet;
        private ClassId value;

        BuilderWithParent(OFOxmBsnIngressPortGroupIdVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x32804L;
    }

    @Override
    public ClassId getValue() {
        return value;
    }

    @Override
    public OFOxmBsnIngressPortGroupId.Builder setValue(ClassId value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<ClassId> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public ClassId getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<ClassId> getMatchField() {
        return MatchField.BSN_INGRESS_PORT_GROUP_ID;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFOxmBsnIngressPortGroupId build() {
                ClassId value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmBsnIngressPortGroupIdVer13(
                    value
                );
        }

    }

    static class Builder implements OFOxmBsnIngressPortGroupId.Builder {
        // OF message fields
        private boolean valueSet;
        private ClassId value;

    @Override
    public long getTypeLen() {
        return 0x32804L;
    }

    @Override
    public ClassId getValue() {
        return value;
    }

    @Override
    public OFOxmBsnIngressPortGroupId.Builder setValue(ClassId value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<ClassId> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public ClassId getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<ClassId> getMatchField() {
        return MatchField.BSN_INGRESS_PORT_GROUP_ID;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFOxmBsnIngressPortGroupId build() {
            ClassId value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmBsnIngressPortGroupIdVer13(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmBsnIngressPortGroupId> {
        @Override
        public OFOxmBsnIngressPortGroupId readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x32804L
            int typeLen = bb.readInt();
            if(typeLen != 0x32804)
                throw new OFParseError("Wrong typeLen: Expected=0x32804L(0x32804L), got="+typeLen);
            ClassId value = ClassId.read4Bytes(bb);

            OFOxmBsnIngressPortGroupIdVer13 oxmBsnIngressPortGroupIdVer13 = new OFOxmBsnIngressPortGroupIdVer13(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmBsnIngressPortGroupIdVer13);
            return oxmBsnIngressPortGroupIdVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmBsnIngressPortGroupIdVer13Funnel FUNNEL = new OFOxmBsnIngressPortGroupIdVer13Funnel();
    static class OFOxmBsnIngressPortGroupIdVer13Funnel implements Funnel<OFOxmBsnIngressPortGroupIdVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmBsnIngressPortGroupIdVer13 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x32804L
            sink.putInt(0x32804);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmBsnIngressPortGroupIdVer13> {
        @Override
        public void write(ByteBuf bb, OFOxmBsnIngressPortGroupIdVer13 message) {
            // fixed value property typeLen = 0x32804L
            bb.writeInt(0x32804);
            message.value.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmBsnIngressPortGroupIdVer13(");
        b.append("value=").append(value);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFOxmBsnIngressPortGroupIdVer13 other = (OFOxmBsnIngressPortGroupIdVer13) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        return result;
    }

}
